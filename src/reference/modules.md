% Modules

### Modules

A module is a container for zero or more [items](#items).

A _module item_ is a module, surrounded in braces, named, and prefixed with the
keyword `mod`. A module item introduces a new, named module into the tree of
modules making up a crate. Modules can nest arbitrarily.

An example of a module:

```
mod math {
    type Complex = (f64, f64);
    fn sin(f: f64) -> f64 {
        /* ... */
# panic!();
    }
    fn cos(f: f64) -> f64 {
        /* ... */
# panic!();
    }
    fn tan(f: f64) -> f64 {
        /* ... */
# panic!();
    }
}
```

Modules and types share the same namespace. Declaring a named type with
the same name as a module in scope is forbidden: that is, a type definition,
trait, struct, enumeration, or type parameter can't shadow the name of a module
in scope, or vice versa.

A module without a body is loaded from an external file, by default with the
same name as the module, plus the `.rs` extension. When a nested submodule is
loaded from an external file, it is loaded from a subdirectory path that
mirrors the module hierarchy.

```{.ignore}
// Load the `vec` module from `vec.rs`
mod vec;

mod thread {
    // Load the `local_data` module from `thread/local_data.rs`
    // or `thread/local_data/mod.rs`.
    mod local_data;
}
```

The directories and files used for loading external file modules can be
influenced with the `path` attribute.

```{.ignore}
#[path = "thread_files"]
mod thread {
    // Load the `local_data` module from `thread_files/tls.rs`
    #[path = "tls.rs"]
    mod local_data;
}
```

