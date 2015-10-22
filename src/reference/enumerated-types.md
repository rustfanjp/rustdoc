% Enumerated types

### Enumerated types

An *enumerated type* is a nominal, heterogeneous disjoint union type, denoted
by the name of an [`enum` item](#enumerations). [^enumtype]

[^enumtype]: The `enum` type is analogous to a `data` constructor declaration in
             ML, or a *pick ADT* in Limbo.

An [`enum` item](#enumerations) declares both the type and a number of *variant
constructors*, each of which is independently named and takes an optional tuple
of arguments.

New instances of an `enum` can be constructed by calling one of the variant
constructors, in a [call expression](#call-expressions).

Any `enum` value consumes as much memory as the largest variant constructor for
its corresponding `enum` type.

Enum types cannot be denoted *structurally* as types, but must be denoted by
named reference to an [`enum` item](#enumerations).

