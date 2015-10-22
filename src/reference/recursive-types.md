% Recursive types

### Recursive types

Nominal types &mdash; [enumerations](#enumerated-types) and
[structures](#structure-types) &mdash; may be recursive. That is, each `enum`
constructor or `struct` field may refer, directly or indirectly, to the
enclosing `enum` or `struct` type itself. Such recursion has restrictions:

* Recursive types must include a nominal type in the recursion
  (not mere [type definitions](grammar.html#type-definitions),
   or other structural types such as [arrays](#array,-and-slice-types) or [tuples](#tuple-types)).
* A recursive `enum` item must have at least one non-recursive constructor
  (in order to give the recursion a basis case).
* The size of a recursive type must be finite;
  in other words the recursive fields of the type must be [pointer types](#pointer-types).
* Recursive type definitions can cross module boundaries, but not module *visibility* boundaries,
  or crate boundaries (in order to simplify the module system and type checker).

An example of a *recursive* type and its use:

```
enum List<T> {
    Nil,
    Cons(T, Box<List<T>>)
}

let a: List<i32> = List::Cons(7, Box::new(List::Cons(13, Box::new(List::Nil))));
```

