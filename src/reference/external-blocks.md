% External blocks

### External blocks

externブロック(external block)は、Rustの外部関数インターフェース(Foregin FUnction Interface, FFI)の基礎となります。
externブロック内の宣言は、非Rustライブラリのシンボルを示します。

externブロック内の関数(function)は、普通のRust関数と同様に定義されます。
ただし、externブロック内の関数は、本体を持たず、セミコロン(`;`)で終端されます。

externブロック内の関数は、あたかもRustコードとして関数が定義されているかの様に、Rustコード内から呼び出す事が出来ます。
Rustコンパイラは自動的にABIの翻訳を行います。

いくつかの[アトリビュート(attribute)][attributes]はexternブロックの振舞を制御します。

[attributes]: attributes.html

デフォルトでは、externブロックは、呼び出そうとしているライブラリは標準Cの"cdecl"ABIを使用していると想定します。
他のABIは、`abi`文字列によって指定します。

```rust
// Interface to the Windows API
extern "stdcall" { }
```

`link`アトリビュートはライブラリの名前を指定します。
Rustコンパイラは、指定された名前をもつネイティブライブラリに対してリンクしようとします。

```rust
#[link(name = "crypto")]
extern { }
```

externブロック内で宣言された関数の型は、`extern "abi" fn(A1, ..., A2) ->R`となります。
`A1 ... An`は仮引数の型であり、`R`は返値型です。

空の外部ブロックに対して`link`アトリビュートを付けても良いです。
これによって、それぞれの外部ブロックに対してアトリビュートを付ける必要が無くなります。
