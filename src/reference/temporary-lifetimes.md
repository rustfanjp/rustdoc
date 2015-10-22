% Temporary lifetimes

##### Temporary lifetimes

When an rvalue is used in an lvalue context, a temporary un-named
lvalue is created and used instead. The lifetime of temporary values
is typically the innermost enclosing statement; the tail expression of
a block is considered part of the statement that encloses the block.

When a temporary rvalue is being created that is assigned into a `let`
declaration, however, the temporary is created with the lifetime of
the enclosing block instead, as using the enclosing statement (the
`let` declaration) would be a guaranteed error (since a pointer to the
temporary would be stored into a variable, but the temporary would be
freed before the variable could be used). The compiler uses simple
syntactic rules to decide which values are being assigned into a `let`
binding, and therefore deserve a longer temporary lifetime.

Here are some examples:

- `let x = foo(&temp())`. The expression `temp()` is an rvalue. As it
  is being borrowed, a temporary is created which will be freed after
  the innermost enclosing statement (the `let` declaration, in this case).
- `let x = temp().foo()`. This is the same as the previous example,
  except that the value of `temp()` is being borrowed via autoref on a
  method-call. Here we are assuming that `foo()` is an `&self` method
  defined in some trait, say `Foo`. In other words, the expression
  `temp().foo()` is equivalent to `Foo::foo(&temp())`.
- `let x = &temp()`. Here, the same temporary is being assigned into
  `x`, rather than being passed as a parameter, and hence the
  temporary's lifetime is considered to be the enclosing block.
- `let x = SomeStruct { foo: &temp() }`. As in the previous case, the
  temporary is assigned into a struct which is then assigned into a
  binding, and hence it is given the lifetime of the enclosing block.
- `let x = [ &temp() ]`. As in the previous case, the
  temporary is assigned into an array which is then assigned into a
  binding, and hence it is given the lifetime of the enclosing block.
- `let ref x = temp()`. In this case, the temporary is created using a ref binding,
  but the result is the same: the lifetime is extended to the enclosing block.

