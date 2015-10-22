% Call expressions

### Call expressions

A _call expression_ invokes a function, providing zero or more input variables
and an optional location to move the function's output into. If the function
eventually returns, then the expression completes.

Some examples of call expressions:

```
# fn add(x: i32, y: i32) -> i32 { 0 }

let x: i32 = add(1i32, 2i32);
let pi: Result<f32, _> = "3.14".parse();
```

