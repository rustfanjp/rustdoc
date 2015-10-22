% Function types

### Function types

The function type constructor `fn` forms new function types. A function type
consists of a possibly-empty set of function-type modifiers (such as `unsafe`
or `extern`), a sequence of input types and an output type.

An example of a `fn` type:

```
fn add(x: i32, y: i32) -> i32 {
  return x + y;
}

let mut x = add(5,7);

type Binop = fn(i32, i32) -> i32;
let bo: Binop = add;
x = bo(5,7);
```

