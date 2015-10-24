% Attributes

## Attributes

いかなるアイテム(item)の宣言も _アトリビュート(attribute)_を持てます。
RustのアトリビュートはECMA-335でモデル化され、文法は、ECMA-334(C#)から来ています。
アトリビュートは一般的には、自由形式のメタデータです。
アトリビュートは、名前、慣習、言語、コンパイラバージョン等として解釈されます。
アトリビュートは次の様な形式を持ちます。

* 1つの識別子、アトリビュート名
* 識別子 '=' リテラルの形式、キー/値ペア
* 括弧で囲まれた識別子のリスト、サブアトリビュートに対する引数

"#!"で始まるアトリビュートは、アトリビュートを囲んでいるアイテムに適応されます。
"#"だけで始まるアトリビュートは、直後に続くアイテムに適応されます。

```rust
// General metadata applied to the enclosing module or crate.
#![crate_type = "lib"]

// A function marked as a unit test
#[test]
fn test_foo() {
  /* ... */
}

// A conditionally-compiled module
#[cfg(target_os="linux")]
mod bar {
  /* ... */
}

// A lint attribute used to suppress a warning/error
#[allow(non_camel_case_types)]
type int8_t = i8;
```

> **ノート:** 将来のいつか、コンパイラは、予約済アトリビュートとユーザー定義アトリビュートを区別します。
> 今の所所は違いは有りません。
