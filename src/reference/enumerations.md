% Enumerations

### Enumerations

_列挙子(enumeration)_ は、[列挙型(enumerated type)][enumerated-types]の同時定義で、さらに *コンストラクタ(constructor)*も定義します。
これによって、列挙型の値を作ったり、パターンマッチを行ったり出来ます。

列挙子は、`enum`キーワードと共に宣言されます。

`enum`アイテム(item)の例です。

```
enum Animal {
    Dog,
    Cat,
}

let mut a: Animal = Animal::Dog;
a = Animal::Cat;
```

列挙子のコンストラクタは、名前付き/無名フィールドを持てます。

```rust
enum Animal {
    Dog (String, f64),
    Cat { name: String, weight: f64 }
}

let mut a: Animal = Animal::Dog("Cocoa".to_string(), 37.2);
a = Animal::Cat { name: "Spotty".to_string(), weight: 2.7 };
```

この場合、`Cat`は、 _構造体列挙子バリアント(struct-like enum variant)_ です。
一方で、`Dog`は単なる列挙子バリアントです。

列挙子は判別子を持ちます。
判別子には値を割り当てられます。

```
enum Foo {
    Bar = 123,
}
```

もし、判別子が割り当てられなかった場合、0から始まり、それぞれのバリアント毎に1ずつ増えて生きます。
列挙子からその内部の値にキャストできます。

```
# enum Foo { Bar = 123 }
let x = Foo::Bar as u32; // x is now 123u32
```

これは、列挙子にバリアントが割り当てられていない場合にのみ許されます。
例えば、`Bar(i32)`という列挙子バリアントを持っている場合、キャストは許されません。

(訳注) ちょっと分かり辛いですが、C/C++で言うenumとunionの合いの子見たいな物です。
