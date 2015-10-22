% While let loops

### While let loops

A `while let` loop is semantically identical to a `while` loop but in place of a
condition expression it expects a refutable let statement. If the value of the
expression on the right hand side of the let statement matches the pattern, the
loop body block executes and control returns to the pattern matching statement.
Otherwise, the while expression completes.

