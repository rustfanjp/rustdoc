% Type aliases

### Type aliases

A _type alias_ defines a new name for an existing [type](#types). Type
aliases are declared with the keyword `type`. Every value has a single,
specific type, but may implement several different traits, or be compatible with
several different type constraints.

For example, the following defines the type `Point` as a synonym for the type
`(u8, u8)`, the type of pairs of unsigned 8 bit integers:

```
type Point = (u8, u8);
let p: Point = (41, 68);
```

