% Inline attributes

### Inline attributes

The inline attribute suggests that the compiler should place a copy of
the function or static in the caller, rather than generating code to
call the function or access the static where it is defined.

The compiler automatically inlines functions based on internal heuristics.
Incorrectly inlining functions can actually make the program slower, so it
should be used with care.

`#[inline]` and `#[inline(always)]` always cause the function to be serialized
into the crate metadata to allow cross-crate inlining.

There are three different types of inline attributes:

* `#[inline]` hints the compiler to perform an inline expansion.
* `#[inline(always)]` asks the compiler to always perform an inline expansion.
* `#[inline(never)]` asks the compiler to never perform an inline expansion.

