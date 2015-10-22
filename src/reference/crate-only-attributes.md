% Crate-only attributes

### Crate-only attributes

- `crate_name` - specify the crate's crate name.
- `crate_type` - see [linkage](#linkage).
- `feature` - see [compiler features](#compiler-features).
- `no_builtins` - disable optimizing certain code patterns to invocations of
                  library functions that are assumed to exist
- `no_main` - disable emitting the `main` symbol. Useful when some other
   object being linked to defines `main`.
- `no_start` - disable linking to the `native` crate, which specifies the
  "start" language item.
- `no_std` - disable linking to the `std` crate.
- `plugin` — load a list of named crates as compiler plugins, e.g.
             `#![plugin(foo, bar)]`. Optional arguments for each plugin,
             i.e. `#![plugin(foo(... args ...))]`, are provided to the plugin's
             registrar function.  The `plugin` feature gate is required to use
             this attribute.

