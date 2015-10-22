% Generic functions

#### Generic functions

A _generic function_ allows one or more _parameterized types_ to appear in its
signature. Each type parameter must be explicitly declared, in an
angle-bracket-enclosed, comma-separated list following the function name.

```rust,ignore
// foo is generic over A and B

fn foo<A, B>(x: A, y: B) {
```

Inside the function signature and body, the name of the type parameter can be
used as a type name. [Trait](#traits) bounds can be specified for type parameters
to allow methods with that trait to be called on values of that type. This is
specified using the `where` syntax:

```rust,ignore
fn foo<T>(x: T) where T: Debug {
```

When a generic function is referenced, its type is instantiated based on the
context of the reference. For example, calling the `foo` function here:

```
use std::fmt::Debug;

fn foo<T>(x: &[T]) where T: Debug {
    // details elided
    # ()
}

foo(&[1, 2]);
```

will instantiate type parameter `T` with `i32`.

The type parameters can also be explicitly supplied in a trailing
[path](#paths) component after the function name. This might be necessary if
there is not sufficient context to determine the type parameters. For example,
`mem::size_of::<u32>() == 4`.

