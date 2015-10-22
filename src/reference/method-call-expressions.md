% Method-call expressions

### Method-call expressions

A _method call_ consists of an expression followed by a single dot, an
identifier, and a parenthesized expression-list. Method calls are resolved to
methods on specific traits, either statically dispatching to a method if the
exact `self`-type of the left-hand-side is known, or dynamically dispatching if
the left-hand-side expression is an indirect [trait object](#trait-objects).

