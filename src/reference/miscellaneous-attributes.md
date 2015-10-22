% Miscellaneous attributes

### Miscellaneous attributes

- `export_name` - on statics and functions, this determines the name of the
  exported symbol.
- `link_section` - on statics and functions, this specifies the section of the
  object file that this item's contents will be placed into.
- `no_mangle` - on any item, do not apply the standard name mangling. Set the
  symbol for this item to its identifier.
- `simd` - on certain tuple structs, derive the arithmetic operators, which
  lower to the target's SIMD instructions, if any; the `simd` feature gate
  is necessary to use this attribute.
- `unsafe_no_drop_flag` - on structs, remove the flag that prevents
  destructors from being run twice. Destructors might be run multiple times on
  the same object with this attribute. To use this, the `unsafe_no_drop_flag` feature
  gate must be enabled.
- `doc` - Doc comments such as `/// foo` are equivalent to `#[doc = "foo"]`.
- `rustc_on_unimplemented` - Write a custom note to be shown along with the error
   when the trait is found to be unimplemented on a type.
   You may use format arguments like `{T}`, `{A}` to correspond to the
   types at the point of use corresponding to the type parameters of the
   trait of the same name. `{Self}` will be replaced with the type that is supposed
   to implement the trait but doesn't. To use this, the `on_unimplemented` feature gate
   must be enabled.

