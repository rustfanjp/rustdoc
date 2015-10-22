% Tuple expressions

### Tuple expressions

Tuples are written by enclosing zero or more comma-separated expressions in
parentheses. They are used to create [tuple-typed](#tuple-types) values.

```{.tuple}
(0.0, 4.5);
("a", 4usize, true);
```

You can disambiguate a single-element tuple from a value in parentheses with a
comma:

```
(0,); // single-element tuple
(0); // zero in parentheses
```

