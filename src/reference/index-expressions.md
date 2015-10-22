% Index expressions

### Index expressions

[Array](#array,-and-slice-types)-typed expressions can be indexed by
writing a square-bracket-enclosed expression (the index) after them. When the
array is mutable, the resulting [lvalue](#lvalues,-rvalues-and-temporaries) can
be assigned to.

Indices are zero-based, and may be of any integral type. Vector access is
bounds-checked at compile-time for constant arrays being accessed with a constant index value.
Otherwise a check will be performed at run-time that will put the thread in a _panicked state_ if it fails.

```{should-fail}
([1, 2, 3, 4])[0];

let x = (["a", "b"])[10]; // compiler error: const index-expr is out of bounds

let n = 10;
let y = (["a", "b"])[n]; // panics

let arr = ["a", "b"];
arr[10]; // panics
```

Also, if the type of the expression to the left of the brackets is a
pointer, it is automatically dereferenced as many times as necessary
to make the indexing possible. In cases of ambiguity, we prefer fewer
autoderefs to more.

