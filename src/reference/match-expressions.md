% Match expressions

### Match expressions

A `match` expression branches on a *pattern*. The exact form of matching that
occurs depends on the pattern. Patterns consist of some combination of
literals, destructured arrays or enum constructors, structures and tuples,
variable binding specifications, wildcards (`..`), and placeholders (`_`). A
`match` expression has a *head expression*, which is the value to compare to
the patterns. The type of the patterns must equal the type of the head
expression.

In a pattern whose head expression has an `enum` type, a placeholder (`_`)
stands for a *single* data field, whereas a wildcard `..` stands for *all* the
fields of a particular variant.

A `match` behaves differently depending on whether or not the head expression
is an [lvalue or an rvalue](#lvalues,-rvalues-and-temporaries). If the head
expression is an rvalue, it is first evaluated into a temporary location, and
the resulting value is sequentially compared to the patterns in the arms until
a match is found. The first arm with a matching pattern is chosen as the branch
target of the `match`, any variables bound by the pattern are assigned to local
variables in the arm's block, and control enters the block.

When the head expression is an lvalue, the match does not allocate a temporary
location (however, a by-value binding may copy or move from the lvalue). When
possible, it is preferable to match on lvalues, as the lifetime of these
matches inherits the lifetime of the lvalue, rather than being restricted to
the inside of the match.

An example of a `match` expression:

```
let x = 1;

match x {
    1 => println!("one"),
    2 => println!("two"),
    3 => println!("three"),
    4 => println!("four"),
    5 => println!("five"),
    _ => println!("something else"),
}
```

Patterns that bind variables default to binding to a copy or move of the
matched value (depending on the matched value's type). This can be changed to
bind to a reference by using the `ref` keyword, or to a mutable reference using
`ref mut`.

Subpatterns can also be bound to variables by the use of the syntax `variable @
subpattern`. For example:

```
let x = 1;

match x {
    e @ 1 ... 5 => println!("got a range element {}", e),
    _ => println!("anything"),
}
```

Patterns can also dereference pointers by using the `&`, `&mut` and `box`
symbols, as appropriate. For example, these two matches on `x: &i32` are
equivalent:

```
# let x = &3;
let y = match *x { 0 => "zero", _ => "some" };
let z = match x { &0 => "zero", _ => "some" };

assert_eq!(y, z);
```

A pattern that's just an identifier, like `Nil` in the previous example, could
either refer to an enum variant that's in scope, or bind a new variable. The
compiler resolves this ambiguity by forbidding variable bindings that occur in
`match` patterns from shadowing names of variants that are in scope. For
example, wherever `List` is in scope, a `match` pattern would not be able to
bind `Nil` as a new name. The compiler interprets a variable pattern `x` as a
binding _only_ if there is no variant named `x` in scope. A convention you can
use to avoid conflicts is simply to name variants with upper-case letters, and
local variables with lower-case letters.

Multiple match patterns may be joined with the `|` operator. A range of values
may be specified with `...`. For example:

```
# let x = 2;

let message = match x {
  0 | 1  => "not many",
  2 ... 9 => "a few",
  _      => "lots"
};
```

Range patterns only work on scalar types (like integers and characters; not
like arrays and structs, which have sub-components). A range pattern may not
be a sub-range of another range pattern inside the same `match`.

Finally, match patterns can accept *pattern guards* to further refine the
criteria for matching a case. Pattern guards appear after the pattern and
consist of a bool-typed expression following the `if` keyword. A pattern guard
may refer to the variables bound within the pattern they follow.

```
# let maybe_digit = Some(0);
# fn process_digit(i: i32) { }
# fn process_other(i: i32) { }

let message = match maybe_digit {
  Some(x) if x < 10 => process_digit(x),
  Some(x) => process_other(x),
  None => panic!()
};
```

