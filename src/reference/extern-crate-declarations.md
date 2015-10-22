% Extern crate declarations

#### Extern crate declarations

An _`extern crate` declaration_ specifies a dependency on an external crate.
The external crate is then bound into the declaring scope as the `ident`
provided in the `extern_crate_decl`.

The external crate is resolved to a specific `soname` at compile time, and a
runtime linkage requirement to that `soname` is passed to the linker for
loading at runtime. The `soname` is resolved at compile time by scanning the
compiler's library path and matching the optional `crateid` provided against
the `crateid` attributes that were declared on the external crate when it was
compiled. If no `crateid` is provided, a default `name` attribute is assumed,
equal to the `ident` given in the `extern_crate_decl`.

Three examples of `extern crate` declarations:

```{.ignore}
extern crate pcre;

extern crate std; // equivalent to: extern crate std as std;

extern crate std as ruststd; // linking to 'std' under another name
```

