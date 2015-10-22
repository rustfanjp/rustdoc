% Block expressions

### Block expressions

A _block expression_ is similar to a module in terms of the declarations that
are possible. Each block conceptually introduces a new namespace scope. Use
items can bring new names into scopes and declared items are in scope for only
the block itself.

A block will execute each statement sequentially, and then execute the
expression (if given). If the block ends in a statement, its value is `()`:

```
let x: () = { println!("Hello."); };
```

If it ends in an expression, its value and type are that of the expression:

```
let x: i32 = { println!("Hello."); 5 };

assert_eq!(5, x);
```

