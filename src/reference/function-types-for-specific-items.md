% Function types for specific items

#### Function types for specific items

Internal to the compiler, there are also function types that are specific to a particular
function item. In the following snippet, for example, the internal types of the functions
`foo` and `bar` are different, despite the fact that they have the same signature:

```
fn foo() { }
fn bar() { }
```

The types of `foo` and `bar` can both be implicitly coerced to the fn
pointer type `fn()`. There is currently no syntax for unique fn types,
though the compiler will emit a type like `fn() {foo}` in error
messages to indicate "the unique fn type for the function `foo`".

