% Array expressions

### Array expressions

An [array](#array,-and-slice-types) _expression_ is written by enclosing zero
or more comma-separated expressions of uniform type in square brackets.

In the `[expr ';' expr]` form, the expression after the `';'` must be a
constant expression that can be evaluated at compile time, such as a
[literal](#literals) or a [static item](#static-items).

```
[1, 2, 3, 4];
["a", "b", "c", "d"];
[0; 128];              // array with 128 zeros
[0u8, 0u8, 0u8, 0u8];
```

