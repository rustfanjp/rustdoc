% Compiler Features

### Compiler Features

Certain aspects of Rust may be implemented in the compiler, but they're not
necessarily ready for every-day use. These features are often of "prototype
quality" or "almost production ready", but may not be stable enough to be
considered a full-fledged language feature.

For this reason, Rust recognizes a special crate-level attribute of the form:

```{.ignore}
#![feature(feature1, feature2, feature3)]
```

This directive informs the compiler that the feature list: `feature1`,
`feature2`, and `feature3` should all be enabled. This is only recognized at a
crate-level, not at a module-level. Without this directive, all features are
considered off, and using the features will result in a compiler error.

The currently implemented features of the reference compiler are:

* `advanced_slice_patterns` - See the [match expressions](#match-expressions)
                              section for discussion; the exact semantics of
                              slice patterns are subject to change, so some types
			      are still unstable.

* `slice_patterns` - OK, actually, slice patterns are just scary and
                     completely unstable.

* `asm` - The `asm!` macro provides a means for inline assembly. This is often
          useful, but the exact syntax for this feature along with its
          semantics are likely to change, so this macro usage must be opted
          into.

* `associated_consts` - Allows constants to be defined in `impl` and `trait`
                        blocks, so that they can be associated with a type or
                        trait in a similar manner to methods and associated
                        types.

* `box_patterns` - Allows `box` patterns, the exact semantics of which
                   is subject to change.

* `box_syntax` - Allows use of `box` expressions, the exact semantics of which
                 is subject to change.

* `concat_idents` - Allows use of the `concat_idents` macro, which is in many
                    ways insufficient for concatenating identifiers, and may be
                    removed entirely for something more wholesome.

* `custom_attribute` - Allows the usage of attributes unknown to the compiler
                       so that new attributes can be added in a backwards compatible
                       manner (RFC 572).

* `custom_derive` - Allows the use of `#[derive(Foo,Bar)]` as sugar for
                    `#[derive_Foo] #[derive_Bar]`, which can be user-defined syntax
                    extensions.

* `intrinsics` - Allows use of the "rust-intrinsics" ABI. Compiler intrinsics
                 are inherently unstable and no promise about them is made.

* `lang_items` - Allows use of the `#[lang]` attribute. Like `intrinsics`,
                 lang items are inherently unstable and no promise about them
                 is made.

* `link_args` - This attribute is used to specify custom flags to the linker,
                but usage is strongly discouraged. The compiler's usage of the
                system linker is not guaranteed to continue in the future, and
                if the system linker is not used then specifying custom flags
                doesn't have much meaning.

* `link_llvm_intrinsics` – Allows linking to LLVM intrinsics via
                           `#[link_name="llvm.*"]`.

* `linkage` - Allows use of the `linkage` attribute, which is not portable.

* `log_syntax` - Allows use of the `log_syntax` macro attribute, which is a
                 nasty hack that will certainly be removed.

* `main` - Allows use of the `#[main]` attribute, which changes the entry point
           into a Rust program. This capability is subject to change.

* `macro_reexport` - Allows macros to be re-exported from one crate after being imported
                     from another. This feature was originally designed with the sole
                     use case of the Rust standard library in mind, and is subject to
                     change.

* `non_ascii_idents` - The compiler supports the use of non-ascii identifiers,
                       but the implementation is a little rough around the
                       edges, so this can be seen as an experimental feature
                       for now until the specification of identifiers is fully
                       fleshed out.

* `no_std` - Allows the `#![no_std]` crate attribute, which disables the implicit
             `extern crate std`. This typically requires use of the unstable APIs
             behind the libstd "facade", such as libcore and libcollections. It
             may also cause problems when using syntax extensions, including
             `#[derive]`.

* `on_unimplemented` - Allows the `#[rustc_on_unimplemented]` attribute, which allows
                       trait definitions to add specialized notes to error messages
                       when an implementation was expected but not found.

* `optin_builtin_traits` - Allows the definition of default and negative trait
                           implementations. Experimental.

* `plugin` - Usage of [compiler plugins][plugin] for custom lints or syntax extensions.
             These depend on compiler internals and are subject to change.

* `plugin_registrar` - Indicates that a crate provides [compiler plugins][plugin].

* `quote` - Allows use of the `quote_*!` family of macros, which are
            implemented very poorly and will likely change significantly
            with a proper implementation.

* `rustc_attrs` - Gates internal `#[rustc_*]` attributes which may be
                  for internal use only or have meaning added to them in the future.

* `rustc_diagnostic_macros`- A mysterious feature, used in the implementation
                             of rustc, not meant for mortals.

* `simd` - Allows use of the `#[simd]` attribute, which is overly simple and
           not the SIMD interface we want to expose in the long term.

* `simd_ffi` - Allows use of SIMD vectors in signatures for foreign functions.
               The SIMD interface is subject to change.

* `staged_api` - Allows usage of stability markers and `#![staged_api]` in a
                 crate. Stability markers are also attributes: `#[stable]`,
                 `#[unstable]`, and `#[deprecated]` are the three levels.

* `start` - Allows use of the `#[start]` attribute, which changes the entry point
            into a Rust program. This capability, especially the signature for the
            annotated function, is subject to change.

* `struct_inherit` - Allows using struct inheritance, which is barely
                     implemented and will probably be removed. Don't use this.

* `struct_variant` - Structural enum variants (those with named fields). It is
                     currently unknown whether this style of enum variant is as
                     fully supported as the tuple-forms, and it's not certain
                     that this style of variant should remain in the language.
                     For now this style of variant is hidden behind a feature
                     flag.

* `thread_local` - The usage of the `#[thread_local]` attribute is experimental
                   and should be seen as unstable. This attribute is used to
                   declare a `static` as being unique per-thread leveraging
                   LLVM's implementation which works in concert with the kernel
                   loader and dynamic linker. This is not necessarily available
                   on all platforms, and usage of it is discouraged.

* `trace_macros` - Allows use of the `trace_macros` macro, which is a nasty
                   hack that will certainly be removed.

* `unboxed_closures` - Rust's new closure design, which is currently a work in
                       progress feature with many known bugs.

* `unsafe_no_drop_flag` - Allows use of the `#[unsafe_no_drop_flag]` attribute,
                          which removes hidden flag added to a type that
                          implements the `Drop` trait. The design for the
                          `Drop` flag is subject to change, and this feature
                          may be removed in the future.

* `unmarked_api` - Allows use of items within a `#![staged_api]` crate
                   which have not been marked with a stability marker.
                   Such items should not be allowed by the compiler to exist,
                   so if you need this there probably is a compiler bug.

* `visible_private_types` - Allows public APIs to expose otherwise private
                            types, e.g. as the return type of a public function.
                            This capability may be removed in the future.

* `allow_internal_unstable` - Allows `macro_rules!` macros to be tagged with the
                              `#[allow_internal_unstable]` attribute, designed
                              to allow `std` macros to call
                              `#[unstable]`/feature-gated functionality
                              internally without imposing on callers
                              (i.e. making them behave like function calls in
                              terms of encapsulation).
* - `default_type_parameter_fallback` - Allows type parameter defaults to
                                        influence type inference.

If a feature is promoted to a language feature, then all existing programs will
start to receive compilation warnings about `#![feature]` directives which enabled
the new feature (because the directive is no longer necessary). However, if a
feature is decided to be removed from the language, errors will be issued (if
there isn't a parser error first). The directive in this case is no longer
necessary, and it's likely that existing code will break if the feature isn't
removed.

If an unknown feature is found in a directive, it results in a compiler error.
An unknown feature is one which has never been recognized by the compiler.

