% Macro-related attributes

### Macro-related attributes

- `macro_use` on a `mod` — macros defined in this module will be visible in the
  module's parent, after this module has been included.

- `macro_use` on an `extern crate` — load macros from this crate.  An optional
  list of names `#[macro_use(foo, bar)]` restricts the import to just those
  macros named.  The `extern crate` must appear at the crate root, not inside
  `mod`, which ensures proper function of the [`$crate` macro
  variable](book/macros.html#the-variable-$crate).

- `macro_reexport` on an `extern crate` — re-export the named macros.

- `macro_export` - export a macro for cross-crate usage.

- `no_link` on an `extern crate` — even if we load this crate for macros, don't
  link it into the output.

See the [macros section of the
book](book/macros.html#scoping-and-macro-import/export) for more information on
macro scope.


