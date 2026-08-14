/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for libyaml. */
#include "../src/gen_support_ruby.h"

#include <yaml.h>
#include <string.h>

static mrb_value GenR_yaml_get_version(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int io0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    yaml_get_version(&io0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_int_value(mrb, (mrb_int)io0);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_yaml_get_version_string(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = yaml_get_version_string();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

void SDLStaticGen_OpenRuby_yaml(mrb_state *mrb);
void SDLStaticGen_OpenRuby_yaml(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "YAML");
    mrb_define_module_function(mrb, mod, "get_version", GenR_yaml_get_version, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "get_version_string", GenR_yaml_get_version_string, MRB_ARGS_ANY());
    mrb_define_const(mrb, mod, "YAML_ANY_BREAK", mrb_int_value(mrb, (mrb_int)YAML_ANY_BREAK));
    mrb_define_const(mrb, mod, "YAML_CR_BREAK", mrb_int_value(mrb, (mrb_int)YAML_CR_BREAK));
    mrb_define_const(mrb, mod, "YAML_LN_BREAK", mrb_int_value(mrb, (mrb_int)YAML_LN_BREAK));
    mrb_define_const(mrb, mod, "YAML_CRLN_BREAK", mrb_int_value(mrb, (mrb_int)YAML_CRLN_BREAK));
    mrb_define_const(mrb, mod, "YAML_EMIT_STREAM_START_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_STREAM_START_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_FIRST_DOCUMENT_START_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_FIRST_DOCUMENT_START_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_DOCUMENT_START_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_DOCUMENT_START_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_DOCUMENT_CONTENT_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_DOCUMENT_CONTENT_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_DOCUMENT_END_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_DOCUMENT_END_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_FLOW_SEQUENCE_FIRST_ITEM_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_FLOW_SEQUENCE_FIRST_ITEM_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_FLOW_SEQUENCE_ITEM_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_FLOW_SEQUENCE_ITEM_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_FLOW_MAPPING_FIRST_KEY_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_FLOW_MAPPING_FIRST_KEY_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_FLOW_MAPPING_KEY_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_FLOW_MAPPING_KEY_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_FLOW_MAPPING_SIMPLE_VALUE_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_FLOW_MAPPING_SIMPLE_VALUE_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_FLOW_MAPPING_VALUE_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_FLOW_MAPPING_VALUE_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_BLOCK_SEQUENCE_FIRST_ITEM_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_BLOCK_SEQUENCE_FIRST_ITEM_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_BLOCK_SEQUENCE_ITEM_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_BLOCK_SEQUENCE_ITEM_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_BLOCK_MAPPING_FIRST_KEY_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_BLOCK_MAPPING_FIRST_KEY_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_BLOCK_MAPPING_KEY_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_BLOCK_MAPPING_KEY_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_BLOCK_MAPPING_SIMPLE_VALUE_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_BLOCK_MAPPING_SIMPLE_VALUE_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_BLOCK_MAPPING_VALUE_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_BLOCK_MAPPING_VALUE_STATE));
    mrb_define_const(mrb, mod, "YAML_EMIT_END_STATE", mrb_int_value(mrb, (mrb_int)YAML_EMIT_END_STATE));
    mrb_define_const(mrb, mod, "YAML_ANY_ENCODING", mrb_int_value(mrb, (mrb_int)YAML_ANY_ENCODING));
    mrb_define_const(mrb, mod, "YAML_UTF8_ENCODING", mrb_int_value(mrb, (mrb_int)YAML_UTF8_ENCODING));
    mrb_define_const(mrb, mod, "YAML_UTF16LE_ENCODING", mrb_int_value(mrb, (mrb_int)YAML_UTF16LE_ENCODING));
    mrb_define_const(mrb, mod, "YAML_UTF16BE_ENCODING", mrb_int_value(mrb, (mrb_int)YAML_UTF16BE_ENCODING));
    mrb_define_const(mrb, mod, "YAML_NO_ERROR", mrb_int_value(mrb, (mrb_int)YAML_NO_ERROR));
    mrb_define_const(mrb, mod, "YAML_MEMORY_ERROR", mrb_int_value(mrb, (mrb_int)YAML_MEMORY_ERROR));
    mrb_define_const(mrb, mod, "YAML_READER_ERROR", mrb_int_value(mrb, (mrb_int)YAML_READER_ERROR));
    mrb_define_const(mrb, mod, "YAML_SCANNER_ERROR", mrb_int_value(mrb, (mrb_int)YAML_SCANNER_ERROR));
    mrb_define_const(mrb, mod, "YAML_PARSER_ERROR", mrb_int_value(mrb, (mrb_int)YAML_PARSER_ERROR));
    mrb_define_const(mrb, mod, "YAML_COMPOSER_ERROR", mrb_int_value(mrb, (mrb_int)YAML_COMPOSER_ERROR));
    mrb_define_const(mrb, mod, "YAML_WRITER_ERROR", mrb_int_value(mrb, (mrb_int)YAML_WRITER_ERROR));
    mrb_define_const(mrb, mod, "YAML_EMITTER_ERROR", mrb_int_value(mrb, (mrb_int)YAML_EMITTER_ERROR));
    mrb_define_const(mrb, mod, "YAML_NO_EVENT", mrb_int_value(mrb, (mrb_int)YAML_NO_EVENT));
    mrb_define_const(mrb, mod, "YAML_STREAM_START_EVENT", mrb_int_value(mrb, (mrb_int)YAML_STREAM_START_EVENT));
    mrb_define_const(mrb, mod, "YAML_STREAM_END_EVENT", mrb_int_value(mrb, (mrb_int)YAML_STREAM_END_EVENT));
    mrb_define_const(mrb, mod, "YAML_DOCUMENT_START_EVENT", mrb_int_value(mrb, (mrb_int)YAML_DOCUMENT_START_EVENT));
    mrb_define_const(mrb, mod, "YAML_DOCUMENT_END_EVENT", mrb_int_value(mrb, (mrb_int)YAML_DOCUMENT_END_EVENT));
    mrb_define_const(mrb, mod, "YAML_ALIAS_EVENT", mrb_int_value(mrb, (mrb_int)YAML_ALIAS_EVENT));
    mrb_define_const(mrb, mod, "YAML_SCALAR_EVENT", mrb_int_value(mrb, (mrb_int)YAML_SCALAR_EVENT));
    mrb_define_const(mrb, mod, "YAML_SEQUENCE_START_EVENT", mrb_int_value(mrb, (mrb_int)YAML_SEQUENCE_START_EVENT));
    mrb_define_const(mrb, mod, "YAML_SEQUENCE_END_EVENT", mrb_int_value(mrb, (mrb_int)YAML_SEQUENCE_END_EVENT));
    mrb_define_const(mrb, mod, "YAML_MAPPING_START_EVENT", mrb_int_value(mrb, (mrb_int)YAML_MAPPING_START_EVENT));
    mrb_define_const(mrb, mod, "YAML_MAPPING_END_EVENT", mrb_int_value(mrb, (mrb_int)YAML_MAPPING_END_EVENT));
    mrb_define_const(mrb, mod, "YAML_ANY_MAPPING_STYLE", mrb_int_value(mrb, (mrb_int)YAML_ANY_MAPPING_STYLE));
    mrb_define_const(mrb, mod, "YAML_BLOCK_MAPPING_STYLE", mrb_int_value(mrb, (mrb_int)YAML_BLOCK_MAPPING_STYLE));
    mrb_define_const(mrb, mod, "YAML_FLOW_MAPPING_STYLE", mrb_int_value(mrb, (mrb_int)YAML_FLOW_MAPPING_STYLE));
    mrb_define_const(mrb, mod, "YAML_NO_NODE", mrb_int_value(mrb, (mrb_int)YAML_NO_NODE));
    mrb_define_const(mrb, mod, "YAML_SCALAR_NODE", mrb_int_value(mrb, (mrb_int)YAML_SCALAR_NODE));
    mrb_define_const(mrb, mod, "YAML_SEQUENCE_NODE", mrb_int_value(mrb, (mrb_int)YAML_SEQUENCE_NODE));
    mrb_define_const(mrb, mod, "YAML_MAPPING_NODE", mrb_int_value(mrb, (mrb_int)YAML_MAPPING_NODE));
    mrb_define_const(mrb, mod, "YAML_PARSE_STREAM_START_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_STREAM_START_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_IMPLICIT_DOCUMENT_START_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_IMPLICIT_DOCUMENT_START_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_DOCUMENT_START_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_DOCUMENT_START_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_DOCUMENT_CONTENT_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_DOCUMENT_CONTENT_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_DOCUMENT_END_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_DOCUMENT_END_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_BLOCK_NODE_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_BLOCK_NODE_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_BLOCK_NODE_OR_INDENTLESS_SEQUENCE_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_BLOCK_NODE_OR_INDENTLESS_SEQUENCE_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_FLOW_NODE_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_FLOW_NODE_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_BLOCK_SEQUENCE_FIRST_ENTRY_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_BLOCK_SEQUENCE_FIRST_ENTRY_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_BLOCK_SEQUENCE_ENTRY_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_BLOCK_SEQUENCE_ENTRY_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_INDENTLESS_SEQUENCE_ENTRY_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_INDENTLESS_SEQUENCE_ENTRY_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_BLOCK_MAPPING_FIRST_KEY_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_BLOCK_MAPPING_FIRST_KEY_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_BLOCK_MAPPING_KEY_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_BLOCK_MAPPING_KEY_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_BLOCK_MAPPING_VALUE_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_BLOCK_MAPPING_VALUE_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_FLOW_SEQUENCE_FIRST_ENTRY_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_FLOW_SEQUENCE_FIRST_ENTRY_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_FLOW_SEQUENCE_ENTRY_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_FLOW_SEQUENCE_ENTRY_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_FLOW_SEQUENCE_ENTRY_MAPPING_KEY_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_FLOW_SEQUENCE_ENTRY_MAPPING_KEY_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_FLOW_SEQUENCE_ENTRY_MAPPING_VALUE_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_FLOW_SEQUENCE_ENTRY_MAPPING_VALUE_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_FLOW_SEQUENCE_ENTRY_MAPPING_END_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_FLOW_SEQUENCE_ENTRY_MAPPING_END_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_FLOW_MAPPING_FIRST_KEY_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_FLOW_MAPPING_FIRST_KEY_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_FLOW_MAPPING_KEY_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_FLOW_MAPPING_KEY_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_FLOW_MAPPING_VALUE_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_FLOW_MAPPING_VALUE_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_FLOW_MAPPING_EMPTY_VALUE_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_FLOW_MAPPING_EMPTY_VALUE_STATE));
    mrb_define_const(mrb, mod, "YAML_PARSE_END_STATE", mrb_int_value(mrb, (mrb_int)YAML_PARSE_END_STATE));
    mrb_define_const(mrb, mod, "YAML_ANY_SCALAR_STYLE", mrb_int_value(mrb, (mrb_int)YAML_ANY_SCALAR_STYLE));
    mrb_define_const(mrb, mod, "YAML_PLAIN_SCALAR_STYLE", mrb_int_value(mrb, (mrb_int)YAML_PLAIN_SCALAR_STYLE));
    mrb_define_const(mrb, mod, "YAML_SINGLE_QUOTED_SCALAR_STYLE", mrb_int_value(mrb, (mrb_int)YAML_SINGLE_QUOTED_SCALAR_STYLE));
    mrb_define_const(mrb, mod, "YAML_DOUBLE_QUOTED_SCALAR_STYLE", mrb_int_value(mrb, (mrb_int)YAML_DOUBLE_QUOTED_SCALAR_STYLE));
    mrb_define_const(mrb, mod, "YAML_LITERAL_SCALAR_STYLE", mrb_int_value(mrb, (mrb_int)YAML_LITERAL_SCALAR_STYLE));
    mrb_define_const(mrb, mod, "YAML_FOLDED_SCALAR_STYLE", mrb_int_value(mrb, (mrb_int)YAML_FOLDED_SCALAR_STYLE));
    mrb_define_const(mrb, mod, "YAML_ANY_SEQUENCE_STYLE", mrb_int_value(mrb, (mrb_int)YAML_ANY_SEQUENCE_STYLE));
    mrb_define_const(mrb, mod, "YAML_BLOCK_SEQUENCE_STYLE", mrb_int_value(mrb, (mrb_int)YAML_BLOCK_SEQUENCE_STYLE));
    mrb_define_const(mrb, mod, "YAML_FLOW_SEQUENCE_STYLE", mrb_int_value(mrb, (mrb_int)YAML_FLOW_SEQUENCE_STYLE));
    mrb_define_const(mrb, mod, "YAML_NO_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_NO_TOKEN));
    mrb_define_const(mrb, mod, "YAML_STREAM_START_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_STREAM_START_TOKEN));
    mrb_define_const(mrb, mod, "YAML_STREAM_END_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_STREAM_END_TOKEN));
    mrb_define_const(mrb, mod, "YAML_VERSION_DIRECTIVE_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_VERSION_DIRECTIVE_TOKEN));
    mrb_define_const(mrb, mod, "YAML_TAG_DIRECTIVE_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_TAG_DIRECTIVE_TOKEN));
    mrb_define_const(mrb, mod, "YAML_DOCUMENT_START_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_DOCUMENT_START_TOKEN));
    mrb_define_const(mrb, mod, "YAML_DOCUMENT_END_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_DOCUMENT_END_TOKEN));
    mrb_define_const(mrb, mod, "YAML_BLOCK_SEQUENCE_START_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_BLOCK_SEQUENCE_START_TOKEN));
    mrb_define_const(mrb, mod, "YAML_BLOCK_MAPPING_START_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_BLOCK_MAPPING_START_TOKEN));
    mrb_define_const(mrb, mod, "YAML_BLOCK_END_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_BLOCK_END_TOKEN));
    mrb_define_const(mrb, mod, "YAML_FLOW_SEQUENCE_START_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_FLOW_SEQUENCE_START_TOKEN));
    mrb_define_const(mrb, mod, "YAML_FLOW_SEQUENCE_END_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_FLOW_SEQUENCE_END_TOKEN));
    mrb_define_const(mrb, mod, "YAML_FLOW_MAPPING_START_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_FLOW_MAPPING_START_TOKEN));
    mrb_define_const(mrb, mod, "YAML_FLOW_MAPPING_END_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_FLOW_MAPPING_END_TOKEN));
    mrb_define_const(mrb, mod, "YAML_BLOCK_ENTRY_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_BLOCK_ENTRY_TOKEN));
    mrb_define_const(mrb, mod, "YAML_FLOW_ENTRY_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_FLOW_ENTRY_TOKEN));
    mrb_define_const(mrb, mod, "YAML_KEY_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_KEY_TOKEN));
    mrb_define_const(mrb, mod, "YAML_VALUE_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_VALUE_TOKEN));
    mrb_define_const(mrb, mod, "YAML_ALIAS_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_ALIAS_TOKEN));
    mrb_define_const(mrb, mod, "YAML_ANCHOR_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_ANCHOR_TOKEN));
    mrb_define_const(mrb, mod, "YAML_TAG_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_TAG_TOKEN));
    mrb_define_const(mrb, mod, "YAML_SCALAR_TOKEN", mrb_int_value(mrb, (mrb_int)YAML_SCALAR_TOKEN));
}
