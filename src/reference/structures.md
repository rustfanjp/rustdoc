% Structures

### Structures

A _structure_ is a nominal [structure type](#structure-types) defined with the
keyword `struct`.

An example of a `struct` item and its use:

```
struct Point {x: i32, y: i32}
let p = Point {x: 10, y: 11};
let px: i32 = p.x;
```

A _tuple structure_ is a nominal [tuple type](#tuple-types), also defined with
the keyword `struct`. For example:

```
struct Point(i32, i32);
let p = Point(10, 11);
let px: i32 = match p { Point(x, _) => x };
```

A _unit-like struct_ is a structure without any fields, defined by leaving off
the list of fields entirely. Such types will have a single value. For example:

```
struct Cookie;
let c = [Cookie, Cookie, Cookie, Cookie];
```

The precise memory layout of a structure is not specified. One can specify a
particular layout using the [`repr` attribute](#ffi-attributes).

