% Assignment expressions

#### Assignment expressions

An _assignment expression_ consists of an
[lvalue](#lvalues,-rvalues-and-temporaries) expression followed by an equals
sign (`=`) and an [rvalue](#lvalues,-rvalues-and-temporaries) expression.

Evaluating an assignment expression [either copies or
moves](#moved-and-copied-types) its right-hand operand to its left-hand
operand.

```
# let mut x = 0;
# let y = 0;
x = y;
```

