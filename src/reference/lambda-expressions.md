% Lambda expressions

### Lambda expressions

A _lambda expression_ (sometimes called an "anonymous function expression")
defines a function and denotes it as a value, in a single expression. A lambda
expression is a pipe-symbol-delimited (`|`) list of identifiers followed by an
expression.

A lambda expression denotes a function that maps a list of parameters
(`ident_list`) onto the expression that follows the `ident_list`. The
identifiers in the `ident_list` are the parameters to the function. These
parameters' types need not be specified, as the compiler infers them from
context.

Lambda expressions are most useful when passing functions as arguments to other
functions, as an abbreviation for defining and capturing a separate function.

Significantly, lambda expressions _capture their environment_, which regular
[function definitions](#functions) do not. The exact type of capture depends
on the [function type](#function-types) inferred for the lambda expression. In
the simplest and least-expensive form (analogous to a ```|| { }``` expression),
the lambda expression captures its environment by reference, effectively
borrowing pointers to all outer variables mentioned inside the function.
Alternately, the compiler may infer that a lambda expression should copy or
move values (depending on their type) from the environment into the lambda
expression's captured environment.

In this example, we define a function `ten_times` that takes a higher-order
function argument, and we then call it with a lambda expression as an argument:

```
fn ten_times<F>(f: F) where F: Fn(i32) {
    for index in 0..10 {
        f(index);
    }
}

ten_times(|j| println!("hello, {}", j));
```

