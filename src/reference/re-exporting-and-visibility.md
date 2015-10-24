% Re-exporting and Visibility

### Re-exporting and Visibility

Rustは、`pub use`によってアイテムを再エクスポートして公開する事を許しています。
これによって、今のモジュール内のアイテムを公開する事が出来ます。

```rust
pub use self::implementation::api;

mod implementation {
    pub mod api {
        pub fn f() {}
    }
}

# fn main() {}
```

これは、`implementation::api::f`を参照している外部クレートは、プライバシー侵害している事になります。
一方で、`api::f`のパスに対するアクセスは許可されます。

プライベートなアイテムを再エクスポートする時、これはプライバシーチェインをショートしている事になります。
