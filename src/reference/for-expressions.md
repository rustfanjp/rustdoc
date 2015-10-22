% For expressions

### For expressions

A `for` expression is a syntactic construct for looping over elements provided
by an implementation of `std::iter::IntoIterator`.

An example of a for loop over the contents of an array:

```
# type Foo = i32;
# fn bar(f: &Foo) { }
# let a = 0;
# let b = 0;
# let c = 0;

let v: &[Foo] = &[a, b, c];

for e in v {
    bar(e);
}
```

An example of a for loop over a series of integers:

```
# fn bar(b:usize) { }
for i in 0..256 {
    bar(i);
}
```

Like `loop` expressions, `for` loops can be controlled with `break` or
`continue`, and may optionally have a _label_. See [infinite
loops](#infinite-loops), [break expressions](#break-expressions), and
[continue expressions](#continue-expressions) for more information.

