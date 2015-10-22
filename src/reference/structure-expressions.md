% Structure expressions

### Structure expressions

There are several forms of structure expressions. A _structure expression_
consists of the [path](#paths) of a [structure item](#structures), followed by
a brace-enclosed list of one or more comma-separated name-value pairs,
providing the field values of a new instance of the structure. A field name
can be any identifier, and is separated from its value expression by a colon.
The location denoted by a structure field is mutable if and only if the
enclosing structure is mutable.

A _tuple structure expression_ consists of the [path](#paths) of a [structure
item](#structures), followed by a parenthesized list of one or more
comma-separated expressions (in other words, the path of a structure item
followed by a tuple expression). The structure item must be a tuple structure
item.

A _unit-like structure expression_ consists only of the [path](#paths) of a
[structure item](#structures).

The following are examples of structure expressions:

```
# struct Point { x: f64, y: f64 }
# struct TuplePoint(f64, f64);
# mod game { pub struct User<'a> { pub name: &'a str, pub age: u32, pub score: usize } }
# struct Cookie; fn some_fn<T>(t: T) {}
Point {x: 10.0, y: 20.0};
TuplePoint(10.0, 20.0);
let u = game::User {name: "Joe", age: 35, score: 100_000};
some_fn::<Cookie>(Cookie);
```

A structure expression forms a new value of the named structure type. Note
that for a given *unit-like* structure type, this will always be the same
value.

A structure expression can terminate with the syntax `..` followed by an
expression to denote a functional update. The expression following `..` (the
base) must have the same structure type as the new structure type being formed.
The entire expression denotes the result of constructing a new structure (with
the same type as the base expression) with the given values for the fields that
were explicitly specified and the values in the base expression for all other
fields.

```
# struct Point3d { x: i32, y: i32, z: i32 }
let base = Point3d {x: 1, y: 2, z: 3};
Point3d {y: 0, z: 10, .. base};
```

