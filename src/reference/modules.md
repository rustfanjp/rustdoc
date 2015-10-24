% Modules

### Modules

モジュール(module)は、任意個の[アイテム(item)][items]を持っています。

[items]: items.html

_モジュールアイテム_は、モジュールであり、波括弧で囲まれ、名前を持ち、`mod`キーワードと共に宣言されます。
モジュールアイテムは、新しいモジュールをクレート(crate)のモジュール木に導入します。
モジュールは好きなだけネストできます。

モジュールの例です。

```
mod math {
    type Complex = (f64, f64);
    fn sin(f: f64) -> f64 {
        /* ... */
# panic!();
    }
    fn cos(f: f64) -> f64 {
        /* ... */
# panic!();
    }
    fn tan(f: f64) -> f64 {
        /* ... */
# panic!();
    }
}
```

モジュールと型は、同じ名前空間を持ちます。
あるスコープ内で、同じ名前の型とモジュールを宣言する事は禁止されています。
また、型定義、トレイト(trait)、構造体(struct)、列挙型(enumeration)、型仮引数(type parameter)も同様です。

本体を持たないモジュールは、外部ファイルからロードされます。
デフォルトでは、モジュールの名前に`.rs`拡張子を足したファイル名を探索します。
ネストしたサブモジュールが外部ファイルからロードされる時、モジュール階層に基づいたディレクトリ階層から外部ファイルの位置が推定されます。

```rust
// Load the `vec` module from `vec.rs`
mod vec;

mod thread {
    // Load the `local_data` module from `thread/local_data.rs`
    // or `thread/local_data/mod.rs`.
    mod local_data;
}
```

外部ファイルをロードするためにディレクトリとファイルは`path`アトリビュートによって変更できます。

```rust
#[path = "thread_files"]
mod thread {
    // Load the `local_data` module from `thread_files/tls.rs`
    #[path = "tls.rs"]
    mod local_data;
}
```

