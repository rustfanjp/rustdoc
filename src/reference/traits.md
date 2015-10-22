% Traits

### Traits

A _trait_ describes an abstract interface that types can
implement. This interface consists of associated items, which come in
three varieties:

- functions
- constants
- types

Associated functions whose first parameter is named `self` are called
methods and may be invoked using `.` notation (e.g., `x.foo()`).

All traits define an implicit type parameter `Self` that refers to
"the type that is implementing this interface". Traits may also
contain additional type parameters. These type parameters (including
`Self`) may be constrained by other traits and so forth as usual.

Trait bounds on `Self` are considered "supertraits". These are
required to be acyclic.  Supertraits are somewhat different from other
constraints in that they affect what methods are available in the
vtable when the trait is used as a [trait object](#trait-objects).

Traits are implemented for specific types through separate
[implementations](#implementations).

Consider the following trait:

```
# type Surface = i32;
# type BoundingBox = i32;
trait Shape {
    fn draw(&self, Surface);
    fn bounding_box(&self) -> BoundingBox;
}
```

This defines a trait with two methods. All values that have
[implementations](#implementations) of this trait in scope can have their
`draw` and `bounding_box` methods called, using `value.bounding_box()`
[syntax](#method-call-expressions).

Traits can include default implementations of methods, as in:

```
trait Foo {
    fn bar(&self);
    fn baz(&self) { println!("We called baz."); }
}
```

Here the `baz` method has a default implementation, so types that implement
`Foo` need only implement `bar`. It is also possible for implementing types
to override a method that has a default implementation.

Type parameters can be specified for a trait to make it generic. These appear
after the trait name, using the same syntax used in [generic
functions](#generic-functions).

```
trait Seq<T> {
   fn len(&self) -> u32;
   fn elt_at(&self, n: u32) -> T;
   fn iter<F>(&self, F) where F: Fn(T);
}
```

It is also possible to define associated types for a trait. Consider the
following example of a `Container` trait. Notice how the type is available
for use in the method signatures:

```
trait Container {
    type E;
    fn empty() -> Self;
    fn insert(&mut self, Self::E);
}
```

In order for a type to implement this trait, it must not only provide
implementations for every method, but it must specify the type `E`. Here's
an implementation of `Container` for the standard library type `Vec`:

```
# trait Container {
#     type E;
#     fn empty() -> Self;
#     fn insert(&mut self, Self::E);
# }
impl<T> Container for Vec<T> {
    type E = T;
    fn empty() -> Vec<T> { Vec::new() }
    fn insert(&mut self, x: T) { self.push(x); }
}
```

Generic functions may use traits as _bounds_ on their type parameters. This
will have two effects:

- Only types that have the trait may instantiate the parameter.
- Within the generic function, the methods of the trait can be
  called on values that have the parameter's type.

For example:

```
# type Surface = i32;
# trait Shape { fn draw(&self, Surface); }
fn draw_twice<T: Shape>(surface: Surface, sh: T) {
    sh.draw(surface);
    sh.draw(surface);
}
```

Traits also define an [trait object](#trait-objects) with the same
name as the trait. Values of this type are created by coercing from a
pointer of some specific type to a pointer of trait type. For example,
`&T` could be coerced to `&Shape` if `T: Shape` holds (and similarly
for `Box<T>`). This coercion can either be implicit or
[explicit](#type-cast-expressions). Here is an example of an explicit
coercion:

```
trait Shape { }
impl Shape for i32 { }
let mycircle = 0i32;
let myshape: Box<Shape> = Box::new(mycircle) as Box<Shape>;
```

The resulting value is a box containing the value that was cast, along with
information that identifies the methods of the implementation that was used.
Values with a trait type can have [methods called](#method-call-expressions) on
them, for any method in the trait, and can be used to instantiate type
parameters that are bounded by the trait.

Trait methods may be static, which means that they lack a `self` argument.
This means that they can only be called with function call syntax (`f(x)`) and
not method call syntax (`obj.f()`). The way to refer to the name of a static
method is to qualify it with the trait name, treating the trait name like a
module. For example:

```
trait Num {
    fn from_i32(n: i32) -> Self;
}
impl Num for f64 {
    fn from_i32(n: i32) -> f64 { n as f64 }
}
let x: f64 = Num::from_i32(42);
```

Traits may inherit from other traits. For example, in

```
trait Shape { fn area(&self) -> f64; }
trait Circle : Shape { fn radius(&self) -> f64; }
```

the syntax `Circle : Shape` means that types that implement `Circle` must also
have an implementation for `Shape`. Multiple supertraits are separated by `+`,
`trait Circle : Shape + PartialEq { }`. In an implementation of `Circle` for a
given type `T`, methods can refer to `Shape` methods, since the typechecker
checks that any type with an implementation of `Circle` also has an
implementation of `Shape`.

In type-parameterized functions, methods of the supertrait may be called on
values of subtrait-bound type parameters. Referring to the previous example of
`trait Circle : Shape`:

```
# trait Shape { fn area(&self) -> f64; }
# trait Circle : Shape { fn radius(&self) -> f64; }
fn radius_times_area<T: Circle>(c: T) -> f64 {
    // `c` is both a Circle and a Shape
    c.radius() * c.area()
}
```

Likewise, supertrait methods may also be called on trait objects.

```{.ignore}
# trait Shape { fn area(&self) -> f64; }
# trait Circle : Shape { fn radius(&self) -> f64; }
# impl Shape for i32 { fn area(&self) -> f64 { 0.0 } }
# impl Circle for i32 { fn radius(&self) -> f64 { 0.0 } }
# let mycircle = 0i32;
let mycircle = Box::new(mycircle) as Box<Circle>;
let nonsense = mycircle.radius() * mycircle.area();
```

