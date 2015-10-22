% Continue expressions

### Continue expressions

A `continue` expression has an optional _label_. If the label is absent, then
executing a `continue` expression immediately terminates the current iteration
of the innermost loop enclosing it, returning control to the loop *head*. In
the case of a `while` loop, the head is the conditional expression controlling
the loop. In the case of a `for` loop, the head is the call-expression
controlling the loop. If the label is present, then `continue 'foo` returns
control to the head of the loop with label `'foo`, which need not be the
innermost label enclosing the `break` expression, but must enclose it.

A `continue` expression is only permitted in the body of a loop.

