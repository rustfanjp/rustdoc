% Traits

### Traits

_トレイト(trait) は、型(type)の抽象インターフェイスを記述します。
このインターフェイスは、3種類の付随するアイテム(item)を持ちます。

- 関数(function)
- 定数(constant)
- 型

最初の仮引数が`self`という名前である付随関数は、メソッドとも呼ばれ、`x.foo()`の様に`.`を使った呼び出し規則を持ちます。

全てのトレイトは、暗黙に型パラメタ(type parameter)`Self`を定義します。
`Self`はこのインターフェイスを実装している型を指します。
トレイトは追加で、型仮引数を持つ事も出来ます。
これらの型仮引数は、ほかのトレイトによって制限が付くかもしれません。

`Self`に束縛されているトレイトは、"親トレイト(supertrait)"と見なされる。
トレイトによる束縛は循環しては成らない。
親トレイトは、トレイトが[トレイトオブジェクト(trait object)][trait-objects]として使われた時に、vtableに存在するメソッドに影響を与える点で、ほかの制約とは異なります。

トレイトは、[実装(implementation)][implementations]を通して、実装されます。

[trait-objects]: trait-objects.html
[implementations]: implementations.html

次のトレイトを考えます。

```rust
# type Surface = i32;
# type BoundingBox = i32;
trait Shape {
    fn draw(&self, Surface);
    fn bounding_box(&self) -> BoundingBox;
}
```

このトレイトは2つのメソッドを定義します。
このスコープ内で、このトレイトにたいする実装を持つ全ての値は、`draw`と`bounding_box`メソッドを持ちます。
メソッドは、[メソッド呼び出し式][method-call-expressions]によって呼び出せます。

[method-call-expressions]: method-call-expressions.html

トレイトはデフォルトの実装を記述する事も出来ます。

```rust
trait Foo {
    fn bar(&self);
    fn baz(&self) { println!("We called baz."); }
}
```

ここで、`baz`メソッドはデフォルトの実装を持っています。
従って、それぞれの型は`bar`だけを実装すれば良いです。
デフォルトの実装をオーバーライドする事も出来ます。

型仮引数を指定する事で、トレイトをジェネリック(generic)にする事もできます。
型仮引数はトレイト名の後の指定され、[ジェネリック関数(generic function)][generic-functions]と同様な文法が用いられます。

[generic-functions]: generic-functions.html

```rust
trait Seq<T> {
   fn len(&self) -> u32;
   fn elt_at(&self, n: u32) -> T;
   fn iter<F>(&self, F) where F: Fn(T);
}
```

トレイトに付随型を定義する事もできます。
例えば、次の`Container`トレイトを考えてみます。

```rust
trait Container {
    type E;
    fn empty() -> Self;
    fn insert(&mut self, Self::E);
}
```

型がこのトレイトを実装するにはメソッドだけでなく、`E`型も指定する必要があります。。
これは、標準ライブラリにおける`Vec`型の`Container`の実装です。

```rust
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

ジェネリック関数は、トレイトを型仮引数の _束縛(bound)_ にも用います。
これは次の様な2つの効果が有ります。

- あると例とを実装しているような型だけを仮引数としてインスタンス化します。
- ジェネリック関数の中で、トレイトのメソッドは、仮引数型を持つ値について呼び出す事ができます。

これが例です。

```rust
# type Surface = i32;
# trait Shape { fn draw(&self, Surface); }
fn draw_twice<T: Shape>(surface: Surface, sh: T) {
    sh.draw(surface);
    sh.draw(surface);
}
```

トレイトは、さらに、[トレイトオブジェクト(trait object)][trait-objects]をトレイトと同じ名前で定義できます。
トレイトオブジェクトの値は、ある型のポインターをこのトレイト型にキャストする事で作られます。
例えば、`&T`は`T: Shapre`であれば、`&Shape`にキャストできます。
`Box<T>`についても同様です。
このキャストは暗黙でも[明示的(explicit)][type-cast-expressions]にも行えます。
これが明示的なキャストの例です。

```rust
trait Shape { }
impl Shape for i32 { }
let mycircle = 0i32;
let myshape: Box<Shape> = Box::new(mycircle) as Box<Shape>;
```

この値は、キャストされた値を持つボックス(box)になります。
また、このボックスはどの実装を
トレイト型を持った値は[メソッド呼び出し][method-call-expressions]を用いる事が出来ます。
これは、トレイトに束縛された型仮引数をインスタンス化します。

トレイトメソッドは静的で、`self`実引数を持ちません。
つまり、トレイトメソッドは`f(x)`といった関数呼び出し文法でのみ呼び出せます。
トレイトの静的メソッドを呼び出すには、トレイト名をモジュール名の様にして扱います。

```rust
trait Num {
    fn from_i32(n: i32) -> Self;
}
impl Num for f64 {
    fn from_i32(n: i32) -> f64 { n as f64 }
}
let x: f64 = Num::from_i32(42);
```

トレイトは、他のトレイトから継承(inherit)されることもあります。

```rust
trait Shape { fn area(&self) -> f64; }
trait Circle : Shape { fn radius(&self) -> f64; }
```

`Circle : Shape`という文法は、`Circle`を実装する型は、`Shape`も実装する必要がある事を表します。
複数の親トレイトは `+`によって分けられ、`trait Circle : Shape + PartialEq {}`の様に記述されます。
`Circle`を実装している型`T`は、`Shape`のメソッドも備えています。

型仮引数を持つ関数において、親トレイトのメソッドは、子トレイトに束縛された型仮引数の値で呼び出されるかもしれません。

```rust
# trait Shape { fn area(&self) -> f64; }
# trait Circle : Shape { fn radius(&self) -> f64; }
fn radius_times_area<T: Circle>(c: T) -> f64 {
    // `c` is both a Circle and a Shape
    c.radius() * c.area()
}
```

同様に、親トレイトメソッドは、トレイトオブジェクトで呼び出されるかもしれません。

```rust
# trait Shape { fn area(&self) -> f64; }
# trait Circle : Shape { fn radius(&self) -> f64; }
# impl Shape for i32 { fn area(&self) -> f64 { 0.0 } }
# impl Circle for i32 { fn radius(&self) -> f64 { 0.0 } }
# let mycircle = 0i32;
let mycircle = Box::new(mycircle) as Box<Circle>;
let nonsense = mycircle.radius() * mycircle.area();
```
