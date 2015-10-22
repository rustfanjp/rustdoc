% External blocks

### External blocks

External blocks form the basis for Rust's foreign function interface.
Declarations in an external block describe symbols in external, non-Rust
libraries.

Functions within external blocks are declared in the same way as other Rust
functions, with the exception that they may not have a body and are instead
terminated by a semicolon.

Functions within external blocks may be called by Rust code, just like
functions defined in Rust. The Rust compiler automatically translates between
the Rust ABI and the foreign ABI.

A number of [attributes](#attributes) control the behavior of external blocks.

By default external blocks assume that the library they are calling uses the
standard C "cdecl" ABI. Other ABIs may be specified using an `abi` string, as
shown here:

```ignore
// Interface to the Windows API
extern "stdcall" { }
```

The `link` attribute allows the name of the library to be specified. When
specified the compiler will attempt to link against the native library of the
specified name.

```{.ignore}
#[link(name = "crypto")]
extern { }
```

The type of a function declared in an extern block is `extern "abi" fn(A1, ...,
An) -> R`, where `A1...An` are the declared types of its arguments and `R` is
the declared return type.

It is valid to add the `link` attribute on an empty extern block. You can use
this to satisfy the linking requirements of extern blocks elsewhere in your code
(including upstream crates) instead of adding the attribute to each extern block.

