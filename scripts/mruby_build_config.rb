MRuby::Build.new do |conf|
  conf.toolchain :clang
  %w[mruby-compiler mruby-error mruby-metaprog mruby-math mruby-time
     mruby-struct mruby-sprintf mruby-pack mruby-string-ext mruby-array-ext
     mruby-hash-ext mruby-numeric-ext mruby-object-ext mruby-objectspace
     mruby-enumerator mruby-enum-ext mruby-toplevel-ext mruby-kernel-ext
     mruby-class-ext mruby-compar-ext mruby-data mruby-set mruby-random
     mruby-catch mruby-range-ext mruby-symbol-ext mruby-proc-ext
     mruby-method].each { |g| conf.gem core: g }
end
