% Lint check attributes

### Lint check attributes

A lint check names a potentially undesirable coding pattern, such as
unreachable code or omitted documentation, for the static entity to which the
attribute applies.

For any lint check `C`:

* `allow(C)` overrides the check for `C` so that violations will go
   unreported,
* `deny(C)` signals an error after encountering a violation of `C`,
* `forbid(C)` is the same as `deny(C)`, but also forbids changing the lint
   level afterwards,
* `warn(C)` warns about violations of `C` but continues compilation.

The lint checks supported by the compiler can be found via `rustc -W help`,
along with their default settings.  [Compiler
plugins](book/compiler-plugins.html#lint-plugins) can provide additional lint checks.

```{.ignore}
mod m1 {
    // Missing documentation is ignored here
    #[allow(missing_docs)]
    pub fn undocumented_one() -> i32 { 1 }

    // Missing documentation signals a warning here
    #[warn(missing_docs)]
    pub fn undocumented_too() -> i32 { 2 }

    // Missing documentation signals an error here
    #[deny(missing_docs)]
    pub fn undocumented_end() -> i32 { 3 }
}
```

This example shows how one can use `allow` and `warn` to toggle a particular
check on and off:

```{.ignore}
#[warn(missing_docs)]
mod m2{
    #[allow(missing_docs)]
    mod nested {
        // Missing documentation is ignored here
        pub fn undocumented_one() -> i32 { 1 }

        // Missing documentation signals a warning here,
        // despite the allow above.
        #[warn(missing_docs)]
        pub fn undocumented_two() -> i32 { 2 }
    }

    // Missing documentation signals a warning here
    pub fn undocumented_too() -> i32 { 3 }
}
```

This example shows how one can use `forbid` to disallow uses of `allow` for
that lint check:

```{.ignore}
#[forbid(missing_docs)]
mod m3 {
    // Attempting to toggle warning signals an error here
    #[allow(missing_docs)]
    /// Returns 2.
    pub fn undocumented_too() -> i32 { 2 }
}
```

