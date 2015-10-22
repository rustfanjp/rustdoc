% While loops

### While loops

A `while` loop begins by evaluating the boolean loop conditional expression.
If the loop conditional expression evaluates to `true`, the loop body block
executes and control returns to the loop conditional expression. If the loop
conditional expression evaluates to `false`, the `while` expression completes.

An example:

```
let mut i = 0;

while i < 10 {
    println!("hello");
    i = i + 1;
}
```

Like `loop` expressions, `while` loops can be controlled with `break` or
`continue`, and may optionally have a _label_. See [infinite
loops](#infinite-loops), [break expressions](#break-expressions), and
[continue expressions](#continue-expressions) for more information.

