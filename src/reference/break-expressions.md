% Break expressions

### Break expressions

A `break` expression has an optional _label_. If the label is absent, then
executing a `break` expression immediately terminates the innermost loop
enclosing it. It is only permitted in the body of a loop. If the label is
present, then `break 'foo` terminates the loop with label `'foo`, which need not
be the innermost label enclosing the `break` expression, but must enclose it.

