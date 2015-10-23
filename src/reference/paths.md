% Paths

## Paths

_パス(path)_は、1つ以上の名前修飾子(namespace qualifier)、`::`、によって_論理的_に分割されています。
パスが1つの要素を持つ場合、そのスコープの[アイテム(item)][items]か、[変数(variable)][variables]を指します。
パスが複数の要素を持つ場合、アイテムを指しています。

[items]: items.html
[variables]: variables.html

全てのアイテムはそのクレート(carte)内の_標準パス(canonical path)_を持ちます。
あるアイテムを指すパスは、そのクレート内でのみ意味を持ちます。
クレートを跨ぐグローバルな名前空間は有りません。
アイテムの標準パスはそのクレート内で、アイテムを他のアイテムと識別します。

識別子(identifier)だけから成る単純なパスの例です。

```rust
x;
x::y::z;
```

パスの要素は通常、[識別子][identifiers]ですが、角括弧で囲まれた型引数(type argument)のリストを含んでいるかもしれません。
[式(expression)][expressions]の文脈では、型引数リストは、名前修飾子(`::`)の後に来ます。
これは、(`<`)にまつわる曖昧さを除去するための規則です。
型式(type expression)の文脈では、最後の名前修飾子は省略されます。

[identifiers]: identifieres.html
[expressions]: expressions.html

型引数を含む例です。

```
# struct HashMap<K, V>(K,V);
# fn f() {
# fn id<T>(t: T) -> T { t }
type T = HashMap<i32,String>; // Type arguments used in a type expression
let x  = id::<i32>(10);       // Type arguments used in a call expression
# }
```

パスは、パスの名前解決の意味論を変える修飾子を先頭に伴うかもしれません。

* `::`で始まるパスは、グローバルパスだと見なされ、クレートの直下から名前解決されます。

```rust
mod a {
    pub fn foo() {}
}
mod b {
    pub fn foo() {
        ::a::foo(); // call a's foo function
    }
}
# fn main() {}
```

* `super`キーワードで始まるパスは、親モジュールから名前解決されます。

```rust
mod a {
    pub fn foo() {}
}
mod b {
    pub fn foo() {
        super::a::foo(); // call a's foo function
                         // (訳注) クレートは無名モジュールを直下に持ちます。
    }
}
# fn main() {}
```

* `self`キーワードで始まるパスは、今のモジュールから名前解決されます。

```rust
fn foo() {}
fn bar() {
    self::foo();
}
# fn main() {}
```

