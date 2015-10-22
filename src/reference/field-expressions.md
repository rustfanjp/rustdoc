% Field expressions

### Field expressions

A _field expression_ consists of an expression followed by a single dot and an
identifier, when not immediately followed by a parenthesized expression-list
(the latter is a [method call expression](#method-call-expressions)). A field
expression denotes a field of a [structure](#structure-types).

```{.ignore .field}
mystruct.myfield;
foo().x;
(Struct {a: 10, b: 20}).a;
```

A field access is an [lvalue](#lvalues,-rvalues-and-temporaries) referring to
the value of that field. When the type providing the field inherits mutability,
it can be [assigned](#assignment-expressions) to.

Also, if the type of the expression to the left of the dot is a
pointer, it is automatically dereferenced as many times as necessary
to make the field access possible. In cases of ambiguity, we prefer
fewer autoderefs to more.

