% If let expressions

### If let expressions

An `if let` expression is semantically identical to an `if` expression but in place
of a condition expression it expects a refutable let statement. If the value of the
expression on the right hand side of the let statement matches the pattern, the corresponding
block will execute, otherwise flow proceeds to the first `else` block that follows.

```
let dish = ("Ham", "Eggs");

// this body will be skipped because the pattern is refuted
if let ("Bacon", b) = dish {
    println!("Bacon is served with {}", b);
}

// this body will execute
if let ("Ham", b) = dish {
    println!("Ham is served with {}", b);
}
```

