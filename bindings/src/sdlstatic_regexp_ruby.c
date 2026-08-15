/*
 * sdlstatic_regexp_ruby.c — Ruby's Regexp and MatchData over SDLStatic::Regex.
 *
 * Original SDLStatic code (zlib).
 *
 * mruby ships no regex engine, but its compiler already knows the syntax:
 * every /pattern/flags literal is compiled into a call to Regexp.new (see
 * mruby's codegen_regx), and $1 / $~ compile into ordinary global reads.
 * So defining this class is enough to light up literals and the backref
 * globals — nothing in mruby itself is patched.
 *
 * A SDLStatic_Regex is a cursor: its group accessors describe the most
 * recent search. MatchData must outlive the next search, so it snapshots
 * the subject and the group offsets into an ordinary Ruby object; its
 * methods and the String extensions live in the prelude below, where they
 * are far shorter than the equivalent C.
 */
#include "bindings_core.h"

#include <SDLStatic/bindings.h>
#include <SDLStatic/regex.h>

#include <mruby/array.h>
#include <mruby/compile.h> /* the prelude is compiled at open time */
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/hash.h>
#include <mruby/string.h>
#include <mruby/variable.h>

static void FreeRegexp(mrb_state *mrb, void *p)
{
    (void)mrb;
    SDLStatic_DestroyRegex((SDLStatic_Regex *)p);
}

static const struct mrb_data_type kRegexpType = {"SDLStatic_Regexp", FreeRegexp};

static SDLStatic_Regex *RegexOf(mrb_state *mrb, mrb_value self)
{
    SDLStatic_Regex *regex = (SDLStatic_Regex *)DATA_PTR(self);
    if (regex == NULL)
    {
        mrb_raise(mrb, E_RUNTIME_ERROR, "uninitialized Regexp");
    }
    return regex;
}

/* Ruby's own flag bits, so Regexp.new(src, Regexp::IGNORECASE) behaves and
 * Regexp#options can answer in the same currency. */
enum
{
    kIgnoreCase = 1,
    kExtended = 2,
    kMultiline = 4
};

static mrb_value FlagsToLetters(mrb_state *mrb, mrb_value options)
{
    char letters[4];
    int n = 0;
    if (mrb_nil_p(options) || mrb_false_p(options))
    {
        return mrb_str_new(mrb, "", 0);
    }
    if (mrb_string_p(options))
    {
        return options; /* what a /re/ literal passes */
    }
    if (mrb_true_p(options))
    {
        letters[n++] = 'i'; /* Ruby: any truthy non-integer means /i */
    }
    else
    {
        const mrb_int bits = mrb_integer(mrb_to_int(mrb, options));
        if (bits & kIgnoreCase)
        {
            letters[n++] = 'i';
        }
        if (bits & kExtended)
        {
            letters[n++] = 'x';
        }
        if (bits & kMultiline)
        {
            letters[n++] = 'm';
        }
    }
    return mrb_str_new(mrb, letters, (mrb_int)n);
}

static mrb_value RegexpInit(mrb_state *mrb, mrb_value self)
{
    mrb_value source = mrb_nil_value();
    mrb_value options = mrb_nil_value();
    mrb_value encoding = mrb_nil_value();
    /* mruby's codegen calls Regexp.new(source[, flags[, encoding]]). */
    mrb_get_args(mrb, "S|oo", &source, &options, &encoding);
    (void)encoding; /* patterns are always UTF-8 here */

    const mrb_value letters = FlagsToLetters(mrb, options);
    SDLStatic_Regex *regex = SDLStatic_CompileRegex(mrb_str_to_cstr(mrb, source),
                                                    mrb_str_to_cstr(mrb, letters));
    if (regex == NULL)
    {
        mrb_raise(mrb, mrb_class_get(mrb, "RegexpError"), SDL_GetError());
    }
    SDLStatic_DestroyRegex((SDLStatic_Regex *)DATA_PTR(self)); /* re-initialize */
    mrb_data_init(self, regex, &kRegexpType);
    mrb_iv_set(mrb, self, mrb_intern_lit(mrb, "@source"), source);
    mrb_iv_set(mrb, self, mrb_intern_lit(mrb, "@flags"), letters);
    return self;
}

static mrb_value RegexpSource(mrb_state *mrb, mrb_value self)
{
    return mrb_iv_get(mrb, self, mrb_intern_lit(mrb, "@source"));
}

static mrb_value RegexpOptions(mrb_state *mrb, mrb_value self)
{
    const char *letters = mrb_str_to_cstr(mrb, mrb_iv_get(mrb, self,
                                                          mrb_intern_lit(mrb, "@flags")));
    mrb_int bits = 0;
    for (const char *c = letters; *c != '\0'; c++)
    {
        bits |= (*c == 'i') ? kIgnoreCase : (*c == 'x') ? kExtended : kMultiline;
    }
    return mrb_fixnum_value(bits);
}

static mrb_value RegexpNames(mrb_state *mrb, mrb_value self)
{
    SDLStatic_Regex *regex = RegexOf(mrb, self);
    const int count = SDLStatic_RegexNamedGroupCount(regex);
    mrb_value names = mrb_ary_new_capa(mrb, count);
    for (int i = 0; i < count; i++)
    {
        const char *name = SDLStatic_RegexNamedGroupName(regex, i);
        mrb_ary_push(mrb, names, mrb_str_new_cstr(mrb, (name != NULL) ? name : ""));
    }
    return names;
}

/* Snapshot the cursor into a MatchData, and publish $~ and $1..$9 the way
 * the parser expects to find them. */
static mrb_value BuildMatchData(mrb_state *mrb, SDLStatic_Regex *regex, mrb_value subject)
{
    struct RClass *klass = mrb_class_get(mrb, "MatchData");
    mrb_value match = mrb_obj_new(mrb, klass, 0, NULL);
    const int count = SDLStatic_RegexGroupCount(regex);

    mrb_value begins = mrb_ary_new_capa(mrb, count);
    mrb_value ends = mrb_ary_new_capa(mrb, count);
    for (int i = 0; i < count; i++)
    {
        mrb_ary_push(mrb, begins, mrb_fixnum_value(SDLStatic_RegexGroupBegin(regex, i)));
        mrb_ary_push(mrb, ends, mrb_fixnum_value(SDLStatic_RegexGroupEnd(regex, i)));
    }

    /* name => group index, for MatchData#[] with a name. */
    mrb_value names = mrb_hash_new(mrb);
    const int named = SDLStatic_RegexNamedGroupCount(regex);
    for (int i = 0; i < named; i++)
    {
        const char *name = SDLStatic_RegexNamedGroupName(regex, i);
        if (name == NULL)
        {
            continue;
        }
        const int index = SDLStatic_RegexNamedGroup(regex, name);
        if (index >= 0)
        {
            mrb_hash_set(mrb, names, mrb_str_new_cstr(mrb, name), mrb_fixnum_value(index));
        }
    }

    mrb_iv_set(mrb, match, mrb_intern_lit(mrb, "@string"), subject);
    mrb_iv_set(mrb, match, mrb_intern_lit(mrb, "@begins"), begins);
    mrb_iv_set(mrb, match, mrb_intern_lit(mrb, "@ends"), ends);
    mrb_iv_set(mrb, match, mrb_intern_lit(mrb, "@names"), names);

    mrb_gv_set(mrb, mrb_intern_lit(mrb, "$~"), match);
    for (int i = 1; i <= 9; i++)
    {
        char name[3] = {'$', (char)('0' + i), '\0'};
        const char *text = (i < count) ? SDLStatic_RegexGroup(regex, i) : NULL;
        mrb_gv_set(mrb, mrb_intern_cstr(mrb, name),
                   (text != NULL) ? mrb_str_new_cstr(mrb, text) : mrb_nil_value());
    }
    return match;
}

/* Regexp#match(str, pos = 0) -> MatchData or nil */
static mrb_value RegexpMatch(mrb_state *mrb, mrb_value self)
{
    mrb_value subject = mrb_nil_value();
    mrb_int position = 0;
    mrb_get_args(mrb, "o|i", &subject, &position);
    if (mrb_nil_p(subject))
    {
        mrb_gv_set(mrb, mrb_intern_lit(mrb, "$~"), mrb_nil_value());
        return mrb_nil_value();
    }
    subject = mrb_obj_as_string(mrb, subject);

    SDLStatic_Regex *regex = RegexOf(mrb, self);
    if (position < 0)
    {
        position += (mrb_int)RSTRING_LEN(subject); /* Ruby counts back from the end */
        if (position < 0)
        {
            mrb_gv_set(mrb, mrb_intern_lit(mrb, "$~"), mrb_nil_value());
            return mrb_nil_value();
        }
    }
    if (position > (mrb_int)RSTRING_LEN(subject) ||
        !SDLStatic_RegexSearch(regex, mrb_str_to_cstr(mrb, subject), (int)position))
    {
        mrb_gv_set(mrb, mrb_intern_lit(mrb, "$~"), mrb_nil_value());
        return mrb_nil_value();
    }
    return BuildMatchData(mrb, regex, subject);
}

/* Regexp#match_at(str, pos) -> MatchData or nil; anchored, for scanners. */
static mrb_value RegexpMatchAt(mrb_state *mrb, mrb_value self)
{
    mrb_value subject = mrb_nil_value();
    mrb_int position = 0;
    mrb_get_args(mrb, "oi", &subject, &position);
    subject = mrb_obj_as_string(mrb, subject);

    SDLStatic_Regex *regex = RegexOf(mrb, self);
    if (position < 0 || position > (mrb_int)RSTRING_LEN(subject) ||
        !SDLStatic_RegexMatchAt(regex, mrb_str_to_cstr(mrb, subject), (int)position))
    {
        return mrb_nil_value();
    }
    return BuildMatchData(mrb, regex, subject);
}

/* Regexp#replace(str, replacement, all) — the engine's own substitution,
 * used by String#sub/#gsub when no block is given. */
static mrb_value RegexpReplace(mrb_state *mrb, mrb_value self)
{
    mrb_value subject = mrb_nil_value();
    mrb_value replacement = mrb_nil_value();
    mrb_bool all = FALSE;
    mrb_get_args(mrb, "SSb", &subject, &replacement, &all);

    const char *result = SDLStatic_RegexReplace(RegexOf(mrb, self),
                                                mrb_str_to_cstr(mrb, subject),
                                                mrb_str_to_cstr(mrb, replacement), all != 0);
    if (result == NULL)
    {
        mrb_raise(mrb, E_RUNTIME_ERROR, SDL_GetError());
    }
    return mrb_str_new_cstr(mrb, result);
}

static mrb_value RegexpEscape(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_value text = mrb_nil_value();
    mrb_get_args(mrb, "S", &text);
    char *quoted = SDLStatic_RegexEscape(mrb_str_to_cstr(mrb, text));
    if (quoted == NULL)
    {
        mrb_raise(mrb, E_RUNTIME_ERROR, SDL_GetError());
    }
    const mrb_value result = mrb_str_new_cstr(mrb, quoted);
    SDL_free(quoted);
    return result;
}

/* MatchData and the String methods that take a pattern. Written in Ruby
 * because they are ordinary object code over the snapshot above — the C
 * equivalent would be three times the size and no clearer. */
static const char kPrelude[] =
    "class MatchData\n"
    "  def string; @string; end\n"
    "  def size; @begins.size; end\n"
    "  def length; size; end\n"
    "  def begin(i); b = @begins[index_of(i)]; b && b >= 0 ? b : nil; end\n"
    "  def end(i); e = @ends[index_of(i)]; e && e >= 0 ? e : nil; end\n"
    "  def [](i)\n"
    "    n = index_of(i)\n"
    "    return nil if n.nil? || n >= @begins.size\n"
    "    b = @begins[n]; e = @ends[n]\n"
    "    return nil if b.nil? || b < 0\n"
    "    @string[b, e - b]\n"
    "  end\n"
    "  def to_a; (0...size).map { |i| self[i] }; end\n"
    "  def captures; to_a[1..-1] || []; end\n"
    "  def named_captures\n"
    "    h = {}\n"
    "    @names.each { |name, idx| h[name] = self[idx] }\n"
    "    h\n"
    "  end\n"
    "  def names; @names.keys; end\n"
    "  def pre_match; @string[0, @begins[0]]; end\n"
    "  def post_match; @string[@ends[0]..-1] || ''; end\n"
    "  def to_s; self[0]; end\n"
    "  def inspect; \"#<MatchData #{to_s.inspect}>\"; end\n"
    "  private\n"
    "  def index_of(i)\n"
    "    return i if i.is_a?(Integer)\n"
    "    key = i.to_s\n"
    "    raise IndexError, \"undefined group name reference: #{key}\" unless @names.key?(key)\n"
    "    @names[key]\n"
    "  end\n"
    "end\n"
    "\n"
    "class Regexp\n"
    "  IGNORECASE = 1\n"
    "  EXTENDED = 2\n"
    "  MULTILINE = 4\n"
    "  # /re/ literals compile into Regexp.compile (mruby's codegen_regx),\n"
    "  # not Regexp.new, so this is the constructor the parser reaches for.\n"
    "  def self.compile(source, options = nil, encoding = nil)\n"
    "    new(source, options, encoding)\n"
    "  end\n"
    "  def self.quote(s); escape(s); end\n"
    "  def self.last_match(n = nil); n ? ($~ && $~[n]) : $~; end\n"
    "  def self.union(*patterns)\n"
    "    patterns = patterns[0] if patterns.size == 1 && patterns[0].is_a?(Array)\n"
    "    new(patterns.map { |p| p.is_a?(Regexp) ? p.source : escape(p.to_s) }.join('|'))\n"
    "  end\n"
    "  def =~(str); m = match(str); m && m.begin(0); end\n"
    "  def ===(str); !match(str).nil?; end\n"
    "  def match?(str); !match(str).nil?; end\n"
    "  def to_s; \"(?#{@flags}-mix:#{@source})\"; end\n"
    "  def inspect; \"/#{@source}/#{@flags}\"; end\n"
    "  def ==(other); other.is_a?(Regexp) && source == other.source && options == other.options; end\n"
    "  def scan_from(str, pos)\n"
    "    # Walk forward, guaranteeing progress on empty matches.\n"
    "    m = match(str, pos)\n"
    "    return nil if m.nil?\n"
    "    m\n"
    "  end\n"
    "end\n"
    "\n"
    "class String\n"
    "  alias_method :__sdlstatic_str_index, :index\n"
    "  alias_method :__sdlstatic_str_slice, :[]\n"
    "  alias_method :__sdlstatic_str_split, :split\n"
    "  alias_method :__sdlstatic_str_sub, :sub\n"
    "  alias_method :__sdlstatic_str_gsub, :gsub\n"
    "\n"
    "  def =~(pattern)\n"
    "    return pattern =~ self if pattern.is_a?(Regexp)\n"
    "    raise TypeError, 'type mismatch: String given'\n"
    "  end\n"
    "\n"
    "  def match(pattern, pos = 0)\n"
    "    pattern = Regexp.new(pattern) unless pattern.is_a?(Regexp)\n"
    "    pattern.match(self, pos)\n"
    "  end\n"
    "\n"
    "  def match?(pattern); !match(pattern).nil?; end\n"
    "\n"
    "  def index(pattern, offset = 0)\n"
    "    return __sdlstatic_str_index(pattern, offset) unless pattern.is_a?(Regexp)\n"
    "    m = pattern.match(self, offset)\n"
    "    m && m.begin(0)\n"
    "  end\n"
    "\n"
    "  def [](*args)\n"
    "    return __sdlstatic_str_slice(*args) unless args[0].is_a?(Regexp)\n"
    "    m = args[0].match(self)\n"
    "    return nil if m.nil?\n"
    "    m[args.size > 1 ? args[1] : 0]\n"
    "  end\n"
    "  alias_method :slice, :[]\n"
    "\n"
    "  def scan(pattern)\n"
    "    pattern = Regexp.new(Regexp.escape(pattern.to_s)) unless pattern.is_a?(Regexp)\n"
    "    out = []\n"
    "    pos = 0\n"
    "    while (m = pattern.match(self, pos))\n"
    "      out << (m.size > 1 ? m.captures : m[0])\n"
    "      pos = m.end(0) > m.begin(0) ? m.end(0) : m.end(0) + 1\n"
    "      break if pos > length\n"
    "    end\n"
    "    if block_given?\n"
    "      out.each { |item| yield item }\n"
    "      self\n"
    "    else\n"
    "      out\n"
    "    end\n"
    "  end\n"
    "\n"
    "  def split(pattern = nil, limit = nil)\n"
    "    return limit ? __sdlstatic_str_split(pattern, limit) : __sdlstatic_str_split(pattern) \\\n"
    "      unless pattern.is_a?(Regexp)\n"
    "    out = []\n"
    "    pos = 0\n"
    "    start = 0\n"
    "    while (m = pattern.match(self, pos))\n"
    "      break if limit && limit > 0 && out.size >= limit - 1\n"
    "      if m.end(0) == m.begin(0)\n"
    "        break if m.begin(0) >= length\n"
    "        out << self[start, m.begin(0) + 1 - start]\n"
    "        start = m.begin(0) + 1\n"
    "        pos = start\n"
    "      else\n"
    "        out << self[start, m.begin(0) - start]\n"
    "        out.concat(m.captures) if m.size > 1\n"
    "        start = m.end(0)\n"
    "        pos = start\n"
    "      end\n"
    "    end\n"
    "    out << self[start..-1].to_s\n"
    "    out.pop while !limit && !out.empty? && out[-1] == ''\n"
    "    out\n"
    "  end\n"
    "\n"
    "  def sub(pattern, replacement = nil, &block)\n"
    "    __sdlstatic_replace(pattern, replacement, false, &block)\n"
    "  end\n"
    "\n"
    "  def gsub(pattern, replacement = nil, &block)\n"
    "    __sdlstatic_replace(pattern, replacement, true, &block)\n"
    "  end\n"
    "\n"
    "  def sub!(pattern, replacement = nil, &block)\n"
    "    result = sub(pattern, replacement, &block)\n"
    "    return nil if result == self\n"
    "    replace(result)\n"
    "  end\n"
    "\n"
    "  def gsub!(pattern, replacement = nil, &block)\n"
    "    result = gsub(pattern, replacement, &block)\n"
    "    return nil if result == self\n"
    "    replace(result)\n"
    "  end\n"
    "\n"
    "  private\n"
    "\n"
    "  def __sdlstatic_replace(pattern, replacement, all, &block)\n"
    "    unless pattern.is_a?(Regexp)\n"
    "      return all ? __sdlstatic_str_gsub(pattern, replacement, &block) \\\n"
    "                 : __sdlstatic_str_sub(pattern, replacement, &block)\n"
    "    end\n"
    "    return pattern.replace(self, replacement, all) if replacement && !block\n"
    "    out = ''\n"
    "    pos = 0\n"
    "    start = 0\n"
    "    while (m = pattern.match(self, pos))\n"
    "      out << self[start, m.begin(0) - start]\n"
    "      out << (block ? block.call(m[0]).to_s : replacement.to_s)\n"
    "      if m.end(0) == m.begin(0)\n"
    "        out << self[m.begin(0), 1].to_s\n"
    "        start = m.begin(0) + 1\n"
    "      else\n"
    "        start = m.end(0)\n"
    "      end\n"
    "      pos = start\n"
    "      break unless all\n"
    "      break if pos > length\n"
    "    end\n"
    "    out << self[start..-1].to_s\n"
    "    out\n"
    "  end\n"
    "end\n";

bool SDLStatic_OpenRubyRegexp(mrb_state *mrb)
{
    if (mrb == NULL)
    {
        return SDL_InvalidParamError("mrb");
    }
    struct RClass *regexp = mrb_define_class(mrb, "Regexp", mrb->object_class);
    MRB_SET_INSTANCE_TT(regexp, MRB_TT_CDATA);
    mrb_define_method(mrb, regexp, "initialize", RegexpInit, MRB_ARGS_ARG(1, 2));
    mrb_define_method(mrb, regexp, "source", RegexpSource, MRB_ARGS_NONE());
    mrb_define_method(mrb, regexp, "options", RegexpOptions, MRB_ARGS_NONE());
    mrb_define_method(mrb, regexp, "names", RegexpNames, MRB_ARGS_NONE());
    mrb_define_method(mrb, regexp, "match", RegexpMatch, MRB_ARGS_ARG(1, 1));
    mrb_define_method(mrb, regexp, "match_at", RegexpMatchAt, MRB_ARGS_REQ(2));
    mrb_define_method(mrb, regexp, "replace", RegexpReplace, MRB_ARGS_REQ(3));
    mrb_define_class_method(mrb, regexp, "escape", RegexpEscape, MRB_ARGS_REQ(1));

    mrb_define_class(mrb, "MatchData", mrb->object_class);
    mrb_define_class(mrb, "RegexpError", mrb_class_get(mrb, "StandardError"));

    mrb_load_string(mrb, kPrelude);
    if (mrb->exc != NULL)
    {
        /* A broken prelude is a build-time bug, not a script error: report
           it rather than leaving a half-defined Regexp behind. */
        const mrb_value message = mrb_obj_as_string(mrb, mrb_obj_value(mrb->exc));
        SDL_SetError("Regexp prelude failed: %s", mrb_str_to_cstr(mrb, message));
        mrb->exc = NULL;
        return false;
    }
    return true;
}
