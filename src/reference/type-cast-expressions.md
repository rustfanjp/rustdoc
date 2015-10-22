% Type cast expressions

#### Type cast expressions

A type cast expression is denoted with the binary operator `as`.

Executing an `as` expression casts the value on the left-hand side to the type
on the right-hand side.

An example of an `as` expression:

```
# fn sum(values: &[f64]) -> f64 { 0.0 }
# fn len(values: &[f64]) -> i32 { 0 }

fn average(values: &[f64]) -> f64 {
  let sum: f64 = sum(values);
  let size: f64 = len(values) as f64;
  sum / size
}
```

Some of the conversions which can be done through the `as` operator
can also be done implicitly at various points in the program, such as
argument passing and assignment to a `let` binding with an explicit
type. Implicit conversions are limited to "harmless" conversions that
do not lose information and which have minimal or no risk of
surprising side-effects on the dynamic execution semantics.

