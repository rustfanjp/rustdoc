% Language items

### Language items

Some primitive Rust operations are defined in Rust code, rather than being
implemented directly in C or assembly language. The definitions of these
operations have to be easy for the compiler to find. The `lang` attribute
makes it possible to declare these operations. For example, the `str` module
in the Rust standard library defines the string equality function:

```{.ignore}
#[lang = "str_eq"]
pub fn eq_slice(a: &str, b: &str) -> bool {
    // details elided
}
```

The name `str_eq` has a special meaning to the Rust compiler, and the presence
of this definition means that it will use this definition when generating calls
to the string equality function.

The set of language items is currently considered unstable. A complete
list of the built-in language items will be added in the future.

