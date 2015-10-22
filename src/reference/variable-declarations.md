% Variable declarations

#### Variable declarations

A _variable declaration_ introduces a new set of variable, given by a pattern. The
pattern may be followed by a type annotation, and/or an initializer expression.
When no type annotation is given, the compiler will infer the type, or signal
an error if insufficient type information is available for definite inference.
Any variables introduced by a variable declaration are visible from the point of
declaration until the end of the enclosing block scope.

