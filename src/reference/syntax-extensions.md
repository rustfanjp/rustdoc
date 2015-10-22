% Syntax extensions

# Syntax extensions

A number of minor features of Rust are not central enough to have their own
syntax, and yet are not implementable as functions. Instead, they are given
names, and invoked through a consistent syntax: `some_extension!(...)`.

Users of `rustc` can define new syntax extensions in two ways:

* [Compiler plugins][plugin] can include arbitrary Rust code that
  manipulates syntax trees at compile time. Note that the interface
  for compiler plugins is considered highly unstable.

* [Macros](book/macros.html) define new syntax in a higher-level,
  declarative way.

