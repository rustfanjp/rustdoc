% Functions

### Functions

A _function item_ defines a sequence of [statements](#statements) and an
optional final [expression](#expressions), along with a name and a set of
parameters. Functions are declared with the keyword `fn`. Functions declare a
set of *input* [*variables*](#variables) as parameters, through which the caller
passes arguments into the function, and the *output* [*type*](#types)
of the value the function will return to its caller on completion.

A function may also be copied into a first-class *value*, in which case the
value has the corresponding [*function type*](#function-types), and can be used
otherwise exactly as a function item (with a minor additional cost of calling
the function indirectly).

Every control path in a function logically ends with a `return` expression or a
diverging expression. If the outermost block of a function has a
value-producing expression in its final-expression position, that expression is
interpreted as an implicit `return` expression applied to the final-expression.

An example of a function:

```
fn add(x: i32, y: i32) -> i32 {
    return x + y;
}
```

As with `let` bindings, function arguments are irrefutable patterns, so any
pattern that is valid in a let binding is also valid as an argument.

```
fn first((value, _): (i32, i32)) -> i32 { value }
```


