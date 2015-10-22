% If expressions

### If expressions

An `if` expression is a conditional branch in program control. The form of an
`if` expression is a condition expression, followed by a consequent block, any
number of `else if` conditions and blocks, and an optional trailing `else`
block. The condition expressions must have type `bool`. If a condition
expression evaluates to `true`, the consequent block is executed and any
subsequent `else if` or `else` block is skipped. If a condition expression
evaluates to `false`, the consequent block is skipped and any subsequent `else
if` condition is evaluated. If all `if` and `else if` conditions evaluate to
`false` then any `else` block is executed.

