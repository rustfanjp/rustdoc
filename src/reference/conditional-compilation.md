% Conditional compilation

### Conditional compilation

Sometimes one wants to have different compiler outputs from the same code,
depending on build target, such as targeted operating system, or to enable
release builds.

There are two kinds of configuration options, one that is either defined or not
(`#[cfg(foo)]`), and the other that contains a string that can be checked
against (`#[cfg(bar = "baz")]`). Currently, only compiler-defined configuration
options can have the latter form.

```
// The function is only included in the build when compiling for OSX
#[cfg(target_os = "macos")]
fn macos_only() {
  // ...
}

// This function is only included when either foo or bar is defined
#[cfg(any(foo, bar))]
fn needs_foo_or_bar() {
  // ...
}

// This function is only included when compiling for a unixish OS with a 32-bit
// architecture
#[cfg(all(unix, target_pointer_width = "32"))]
fn on_32bit_unix() {
  // ...
}

// This function is only included when foo is not defined
#[cfg(not(foo))]
fn needs_not_foo() {
  // ...
}
```

This illustrates some conditional compilation can be achieved using the
`#[cfg(...)]` attribute. `any`, `all` and `not` can be used to assemble
arbitrarily complex configurations through nesting.

The following configurations must be defined by the implementation:

* `debug_assertions`. Enabled by default when compiling without optimizations.
  This can be used to enable extra debugging code in development but not in
  production.  For example, it controls the behavior of the standard library's
  `debug_assert!` macro.
* `target_arch = "..."`. Target CPU architecture, such as `"x86"`, `"x86_64"`
  `"mips"`, `"powerpc"`, `"arm"`, or `"aarch64"`.
* `target_endian = "..."`. Endianness of the target CPU, either `"little"` or
  `"big"`.
* `target_family = "..."`. Operating system family of the target, e. g.
  `"unix"` or `"windows"`. The value of this configuration option is defined
  as a configuration itself, like `unix` or `windows`.
* `target_os = "..."`. Operating system of the target, examples include
  `"windows"`, `"macos"`, `"ios"`, `"linux"`, `"android"`, `"freebsd"`, `"dragonfly"`,
  `"bitrig"` , `"openbsd"` or `"netbsd"`.
* `target_pointer_width = "..."`. Target pointer width in bits. This is set
  to `"32"` for targets with 32-bit pointers, and likewise set to `"64"` for
  64-bit pointers.
* `unix`. See `target_family`.
* `windows`. See `target_family`.

You can also set another attribute based on a `cfg` variable with `cfg_attr`:

```rust,ignore
#[cfg_attr(a, b)]
```

Will be the same as `#[b]` if `a` is set by `cfg`, and nothing otherwise.

