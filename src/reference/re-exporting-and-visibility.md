% Re-exporting and Visibility

### Re-exporting and Visibility

Rust allows publicly re-exporting items through a `pub use` directive. Because
this is a public directive, this allows the item to be used in the current
module through the rules above. It essentially allows public access into the
re-exported item. For example, this program is valid:

```
pub use self::implementation::api;

mod implementation {
    pub mod api {
        pub fn f() {}
    }
}

# fn main() {}
```

This means that any external crate referencing `implementation::api::f` would
receive a privacy violation, while the path `api::f` would be allowed.

When re-exporting a private item, it can be thought of as allowing the "privacy
chain" being short-circuited through the reexport instead of passing through
the namespace hierarchy as it normally would.

