% Implementations

### Implementations

_実装(implementatino)_ は、特定の型に対して[トレイト(trait)][traits]を実装するアイテムです。

[traits]: traits.html

実装は、`impl`キーワードと共に定義されます。

```rust
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

トレイト指定する事なく、実装を定義する事も可能です。
その様な実装におけるメソッドは、実装している型の値に対する直接呼び出しでしか使えません。
この場合、`impl`の後に`for`はきません。
トレイトを指定しない実装は、列挙子か構造体にしか使えません。
また、`self`型は、実装している型を示します。

```rust
struct Point {x: i32, y: i32}

impl Point {
    fn log(&self) {
        println!("Point is at ({}, {})", self.x, self.y);
    }
}

let my_point = Point {x: 10, y:11};
my_point.log();
```
`impl`の中でトレイトが指定されると、トライとの中の全てのメソッドは実装されなければなりません。

実装は、型仮引数を取る事もできます。
この型仮引数は、実装しようとしているトレイトが取る型仮引数とは異なっていても良いです。
実装の型仮引数は、`impl`キーワードの後に記述します。

```rust
# trait Seq<T> { fn dummy(&self, _: T) { } }
impl<T> Seq<T> for Vec<T> {
   /* ... */
}
impl Seq<bool> for u32 {
   /* Treat the integer as a sequence of bits */
}
```
