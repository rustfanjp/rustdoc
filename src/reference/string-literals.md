% String literals

##### String literals

A _string literal_ is a sequence of any Unicode characters enclosed within two
`U+0022` (double-quote) characters, with the exception of `U+0022` itself,
which must be _escaped_ by a preceding `U+005C` character (`\`).

Line-break characters are allowed in string literals. Normally they represent
themselves (i.e. no translation), but as a special exception, when a `U+005C`
character (`\`) occurs immediately before the newline, the `U+005C` character,
the newline, and all whitespace at the beginning of the next line are ignored.
Thus `a` and `b` are equal:

```rust
let a = "foobar";
let b = "foo\
         bar";

assert_eq!(a,b);
```

