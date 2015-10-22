% Implementations

### Implementations

An _implementation_ is an item that implements a [trait](#traits) for a
specific type.

Implementations are defined with the keyword `impl`.

```
# #[derive(Copy, Clone)]
# struct Point {x: f64, y: f64};
# type Surface = i32;
# struct BoundingBox {x: f64, y: f64, width: f64, height: f64};
# trait Shape { fn draw(&self, Surface); fn bounding_box(&self) -> BoundingBox; }
# fn do_draw_circle(s: Surface, c: Circle) { }
struct Circle {
    radius: f64,
    center: Point,
}

impl Copy for Circle {}

impl Clone for Circle {
    fn clone(&self) -> Circle { *self }
}

impl Shape for Circle {
    fn draw(&self, s: Surface) { do_draw_circle(s, *self); }
    fn bounding_box(&self) -> BoundingBox {
        let r = self.radius;
        BoundingBox{x: self.center.x - r, y: self.center.y - r,
         width: 2.0 * r, height: 2.0 * r}
    }
}
```

It is possible to define an implementation without referring to a trait. The
methods in such an implementation can only be used as direct calls on the
values of the type that the implementation targets. In such an implementation,
the trait type and `for` after `impl` are omitted. Such implementations are
limited to nominal types (enums, structs), and the implementation must appear
in the same crate as the `self` type:

```
struct Point {x: i32, y: i32}

impl Point {
    fn log(&self) {
        println!("Point is at ({}, {})", self.x, self.y);
    }
}

let my_point = Point {x: 10, y:11};
my_point.log();
```

When a trait _is_ specified in an `impl`, all methods declared as part of the
trait must be implemented, with matching types and type parameter counts.

An implementation can take type parameters, which can be different from the
type parameters taken by the trait it implements. Implementation parameters
are written after the `impl` keyword.

```
# trait Seq<T> { fn dummy(&self, _: T) { } }
impl<T> Seq<T> for Vec<T> {
   /* ... */
}
impl Seq<bool> for u32 {
   /* Treat the integer as a sequence of bits */
}
```

