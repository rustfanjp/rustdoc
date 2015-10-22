% Enumerations

### Enumerations

An _enumeration_ is a simultaneous definition of a nominal [enumerated
type](#enumerated-types) as well as a set of *constructors*, that can be used
to create or pattern-match values of the corresponding enumerated type.

Enumerations are declared with the keyword `enum`.

An example of an `enum` item and its use:

```
enum Animal {
    Dog,
    Cat,
}

let mut a: Animal = Animal::Dog;
a = Animal::Cat;
```

Enumeration constructors can have either named or unnamed fields:

```rust
enum Animal {
    Dog (String, f64),
    Cat { name: String, weight: f64 }
}

let mut a: Animal = Animal::Dog("Cocoa".to_string(), 37.2);
a = Animal::Cat { name: "Spotty".to_string(), weight: 2.7 };
```

In this example, `Cat` is a _struct-like enum variant_,
whereas `Dog` is simply called an enum variant.

Enums have a discriminant. You can assign them explicitly:

```
enum Foo {
    Bar = 123,
}
```

If a discriminant isn't assigned, they start at zero, and add one for each
variant, in order.

You can cast an enum to get this value:

```
# enum Foo { Bar = 123 }
let x = Foo::Bar as u32; // x is now 123u32
```

This only works as long as none of the variants have data attached. If
it were `Bar(i32)`, this is disallowed.

