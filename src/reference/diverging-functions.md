% Diverging functions

#### Diverging functions

A special kind of function can be declared with a `!` character where the
output type would normally be. For example:

```
fn my_err(s: &str) -> ! {
    println!("{}", s);
    panic!();
}
```

We call such functions "diverging" because they never return a value to the
caller. Every control path in a diverging function must end with a `panic!()` or
a call to another diverging function on every control path. The `!` annotation
does *not* denote a type.

It might be necessary to declare a diverging function because as mentioned
previously, the typechecker checks that every control path in a function ends
with a [`return`](#return-expressions) or diverging expression. So, if `my_err`
were declared without the `!` annotation, the following code would not
typecheck:

```
# fn my_err(s: &str) -> ! { panic!() }

fn f(i: i32) -> i32 {
   if i == 42 {
     return 42;
   }
   else {
     my_err("Bad number!");
   }
}
```

This will not compile without the `!` annotation on `my_err`, since the `else`
branch of the conditional in `f` does not return an `i32`, as required by the
signature of `f`. Adding the `!` annotation to `my_err` informs the
typechecker that, should control ever enter `my_err`, no further type judgments
about `f` need to hold, since control will never resume in any context that
relies on those judgments. Thus the return type on `f` only needs to reflect
the `if` branch of the conditional.

