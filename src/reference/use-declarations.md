% Use declarations

#### Use declarations

_use宣言(use declaration)_は、1つ以上の[パス][paths]に対するローカルなシノニムを定義します。
通常、`use`宣言はモジュールアイテム(module item)のパスを短縮するために使われます。
これらの宣言は、[モジュール][modules]と[ブロック][blocks]のトップに現れるかもしれません。

> **ノート**: 他の多くの言語と違い、Rustの`use`宣言は、外部クレートへのリンケージ依存性は宣言しません。
> そのためには、[`extern crate`宣言][extern-crate-declarations]を使用してください。

[paths]: paths.html
[modules]: modules.html
[blocks]: blocks.html

`use`宣言はいくつかの短縮形をサポートします。

* あるターゲットの名前を別のローカルな名前に束縛します。`use p::q::r as x;`
* 最後だけが事なる複数のパスを同時に束縛できます。`use a::b::{c, d, e, f};`
* 最後だけが事なる複数のパスと、それらの親モジュールを同時に束縛できます。`use a::b::{self, c, d};`
* パターンにマッチする全てのパスを一度に束縛できます。`use a::b::*;`

`use`宣言の例です。

```rust
use std::option::Option::{Some, None};
use std::collections::hash_map::{self, HashMap};

fn foo<T>(_: T){}
fn bar(map1: HashMap<String, usize>, map2: hash_map::HashMap<String, usize>){}

fn main() {
    // Equivalent to 'foo(vec![std::option::Option::Some(1.0f64),
    // std::option::Option::None]);'
    foo(vec![Some(1.0f64), None]);

    // Both `hash_map` and `HashMap` are in scope.
    let map1 = HashMap::new();
    let map2 = hash_map::HashMap::new();
    bar(map1, map2);
}
```

他のアイテムと同様に、`use`宣言はデフォルトでモジュール内でプライベート(private)です。
また、他のアイテムと同様に`pub`キーワードで修飾する事で、パブリック(public)にできます。
パブリックな`use`宣言は名前の_再エクスポート(re-export)_として働きます。
パブリックな`use`宣言は、パブリックな名前を別のターゲットに _リダイレクト(redirect)_ 出来ます。
もし、その様なリダイレクトの連鎖が循環し、曖昧さを解決できない場合、コンパイル時エラーとなります。

再エクスポートの例です。

```rust
# fn main() { }
mod quux {
    pub use quux::foo::{bar, baz};

    pub mod foo {
        pub fn bar() { }
        pub fn baz() { }
    }
}
```
この例では、`quux`モジュールは、`foo`で定義された2つのアイテムを再エクスポートしています。
また、`use`アイテムの中で指定されているパスは、標準パスです。
従って、`use`アイテムの中を`foo::{bar, baz}`と書く事は出来ません。
`use`アイテムにいきなり書く事が出来るモジュールは、クレートのルートで宣言された物だけです。
`use`アイテムのパスが、`self`か`super`キーワードから始まった場合、パスは今のモジュールか親モジュールからの相対パスです。
`use`のパス指定のルールは、`extern crate`宣言に対しても同様です。

`use`アイテムの色々な例です。

```rust
# #![allow(unused_imports)]
use foo::baz::foobaz;    // good: foo is at the root of the crate

mod foo {

    mod example {
        pub mod iter {}
    }

    use foo::example::iter; // good: foo is at crate root
//  use example::iter;      // bad:  core is not at the crate root
    use self::baz::foobaz;  // good: self refers to module 'foo'
    use foo::bar::foobar;   // good: foo is at crate root

    pub mod bar {
        pub fn foobar() { }
    }

    pub mod baz {
        use super::bar::foobar; // good: super refers to module 'foo'
        pub fn foobaz() { }
    }
}

fn main() {}
```
