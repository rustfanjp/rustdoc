% Visibility and Privacy

## Visibility and Privacy

可視性(visibility)とプライバシー(privacy)はしばしば混同されます。
これら2つの概念は、「このアイテムはこの場所で使えるのか」という問題を解決します。

Rustのの名前解決は、名前空間のグローバル階層に基づいて行われます。
この階層におけるそれぞれのレベルは、なんらかのアイテムに対応しています。
アイテムには、外部クレート(crate)も含みます。
新たにモジュールを宣言か定義する事はこの階層に新たな木を挿入する事です。

モジュール間のインタフェースを制御するために、Rustは、あるアイテムの使用が許されるかどうかをチェックします。
ここでは、プライバシー警告が生成されます。

デフォルトでは、Rustにおける全ては、 *プライベート* です。
唯一の例外は、列挙バリアント(enum variant)は、デフォルトでパブリックです。
アイテムが`pub`として宣言されると、外側のモジュールからもアクセスできます。

```rust
# fn main() {}
// Declare a private struct
struct Foo;

// Declare a public struct with a private field
pub struct Bar {
    field: i32
}

// Declare a public enum with two public variants
pub enum State {
    PubliclyAccessibleState,
    PubliclyAccessibleState2,
}
```

アイテムがパブリックかプライベートかによって、アイテムへのアクセスは2通り有ります。

1. もしアイテムがパブリックならば、そのアイテムのパブリックな祖先からアクセス出来ます。
2. もしアイテムがプライベートならば、今のモジュールの子孫からアクセス出来ます。

この2つのケースは、APIを公開しながら実装を内側に隠す様なモジュール階層を上で協力なツールとなります。
そこで、いくつかのユースケースを見てみましょう。

* ライブラリ開発者は、そのライブラリにリンクしているクレートに対して機能を公開しなければなりません。
  従って、ライブラリクレートのルートから公開するアイテムまでが`pub`である必要があります。
  この`pub`の連鎖の中にプライベートなアイテムが有ると、外部からアクセスできなくなります。

* クレートは、グローバルな"ヘルパーモジュール"を用いる事が良くあります。
  また、このヘルパーモジュールは、公開したく無いとします。
  これを達成するためには、クレートのルートにヘルパーAPIを持ったプライベートモジュールを持てば良いです。
  このプライベートモジュールの子孫からはヘルパーAPIにアクセスできますが、外からはアクセスできません。

* モジュールに対する単体テストを書く時、テストしたいモジュールの直下に`mod test`モジュールを持たせるのが典型的なイディオムです。
  このテストモジュールは元のモジュールの子孫なので、プライベートメンバにもアクセスできます。

プライベートアイテムに対して"アクセスできる"の意味は、どの種類のアイテムを対象としているかによって異なります。
例えば、アイテムがモジュールである場合、そのモジュールの内側に対してアクセスし内側のアイテムをインポートする事が出来ます。
一方で、関数にアクセスできるというのは、関数を呼び出せるという意味になります。
さらに、パス式(path expression)やインポート文(import statement)は、このパス式やインポート文が指定している場所が、今の可視スコープ内に有る事を意味します。

ここに、これらの例が有ります。

```rust
// This module is private, meaning that no external crate can access this
// module. Because it is private at the root of this current crate, however, any
// module in the crate may access any publicly visible item in this module.
mod crate_helper_module {

    // This function can be used by anything in the current crate
    pub fn crate_helper() {}

    // This function *cannot* be used by anything else in the crate. It is not
    // publicly visible outside of the `crate_helper_module`, so only this
    // current module and its descendants may access it.
    fn implementation_detail() {}
}

// This function is "public to the root" meaning that it's available to external
// crates linking against this one.
pub fn public_api() {}

// Similarly to 'public_api', this module is public so external crates may look
// inside of it.
pub mod submodule {
    use crate_helper_module;

    pub fn my_method() {
        // Any item in the local crate may invoke the helper module's public
        // interface through a combination of the two rules above.
        crate_helper_module::crate_helper();
    }

    // This function is hidden to any module which is not a descendant of
    // `submodule`
    fn my_implementation() {}

    #[cfg(test)]
    mod test {

        #[test]
        fn test_my_implementation() {
            // Because this module is a descendant of `submodule`, it's allowed
            // to access private items inside of `submodule` without a privacy
            // violation.
            super::my_implementation();
        }
    }
}

# fn main() {}
```

全てのrustプログラムは、プライバシーチェックをパスしなければなりません。
そのために、全てのパスが有効なアクセスである必要が有ります。
これには、文、式、型等を含みます。
