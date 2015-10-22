% Attributes

## Attributes

Any item declaration may have an _attribute_ applied to it. Attributes in Rust
are modeled on Attributes in ECMA-335, with the syntax coming from ECMA-334
(C#). An attribute is a general, free-form metadatum that is interpreted
according to name, convention, and language and compiler version. Attributes
may appear as any of:

* A single identifier, the attribute name
* An identifier followed by the equals sign '=' and a literal, providing a
  key/value pair
* An identifier followed by a parenthesized list of sub-attribute arguments

Attributes with a bang ("!") after the hash ("#") apply to the item that the
attribute is declared within. Attributes that do not have a bang after the hash
apply to the item that follows the attribute.

An example of attributes:

```{.rust}
// General metadata applied to the enclosing module or crate.
#![crate_type = "lib"]

// A function marked as a unit test
#[test]
fn test_foo() {
  /* ... */
}

// A conditionally-compiled module
#[cfg(target_os="linux")]
mod bar {
  /* ... */
}

// A lint attribute used to suppress a warning/error
#[allow(non_camel_case_types)]
type int8_t = i8;
```

> **Note:** At some point in the future, the compiler will distinguish between
> language-reserved and user-available attributes. Until then, there is
> effectively no difference between an attribute handled by a loadable syntax
> extension and the compiler.

