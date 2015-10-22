% The Rust Programming Language

ようこそ！
この本は[Rust Programming Language][rust]の解説本です。
Rustはシステムプログラミング言語であり、安全性、速度、平行性の両立を目標としています。
Rustはガベージコレクタ無しでこれらの目標を追及し、他のプログラミング言語では上手に出来ない事が出来ます。
例えば、多言語への埋め込みや、ワークスペース・実行時間の制限、ドライバーやオペレーティングシステムの様な低レベルコードの記述等です。
Rustは、コンパイル時の安全性チェックにより実行時オーバーヘッド無しに全てのデータ競合を排除し、既存のプログラミング言語を改善します。
Rustは、他の高レベルプログラミング言語にありがちな抽象化をゼロコストで行う、'ゼロコスト抽象化'を目標としています。
一方で、Rustは、低レベルプログラミング言語の様な、プログラムの細かな制御を可能にします。

[rust]: https://www.rust-lang.org

"The Rust Programming Language"は次の8つのセクションに分かれます。
このイントロダクションは最初の1つであり、残りは以下の通りです。

* [Getting started][gs] - Rust開発環境の立ち上げ
* [Learn Rust][lr] - Rustのチュートリアル
* [Effective Rust][er] - TODO
* [Syntax and Semantics][ss] - Rustの文法と意味論
* [Nightly Rust][nr] - 開発中のRustの新機能
* [Glossary][gl] - この本における単語の用法
* [Bibliography][bi] - 参考文献

[gs]: getting-started.html
[lr]: learn-rust.html
[er]: effective-rust.html
[ss]: syntax-and-semantics.html
[nr]: nightly-rust.html
[gl]: glossary.html
[bi]: bibliograpy.html

このイントロダクションを読み終えた後、'Learn Rust'か、'Syntax and Semantics'に行くのが良いでしょう。
TODO

### Contributing

この本を生成するソースファイルはGithubにあります。
[github.com/rust-lang/rust/tree/master/src/doc/trpl](https://github.com/rust-lang/rust/tree/master/src/doc/trpl)

(訳注) 日本語訳を生成するソースファイルは以下にあります。
TODO

### Rust イントロダクション

Rustに興味を持ちましたか？
それでは、小さなコードをためして、Rustの力を確認しましょう。

Rustのユニークなコンセプトとして'ownership'があります。
次の例を見てください。

```rust
fn main() {
    let mut x = vec!["Hello", "world"];
}
```
このプログラムは`x`名付けられた[変数束縛(variable binding)][var]を作ります。
この変数束縛の値は`Vec<T>`型の'ベクタ'ですが、これは、標準ライブラリで定義された[マクロ(macro)][macro]を用いて作られています。
このマクロは`vec`と名付けられていて、`!`を伴って呼び出されています。
これは、「make things explicit」というRustの一般原則に従っています。
マクロは関数呼び出しよりもずっと複雑な事を行えるので、関数呼び出しとは異なった見た目をしています。
また、`!`によってパースが容易になり、サードパーティーツールを作るのが容易になります。

ここでは、`x`を作るのに、`mut`を使いました。
Rustにおける変数束縛はデフォルトでimmutableです。
後の例で、このベクタに変更操作を加えるので、ここでは`mut`としました。

ここで、いかなる型情報も記述していないというのは、注目に値するでしょう。
Rustは静的型付け言語ですが、ここでは型を明示的に記述する必要はありませんでした。
Rustは型推論を用いて、静的型付けの力と、型情報記述の煩雑さをバランスさせています。

Rustはヒープアロケーションよりも、スタックアロケーションを好みます。
上の例では`x`はスタックに置かれますが、`Vec<T>`型はベクタ要素のためのスペースをヒープにアロケートします。
もし、この区別に慣れていなければ、今のところはこれを無視してかまいませんし、気になるなら['The Stack and the Heap)][heap]を確認して下さい。
Rustは、メモリアロケーションを制御する能力を持っていますが、イントロダクションとしては重要ではありません。

[var]: variable-bindings.html
[macro]: macros.html
[heap]: the-stack-and-the-heap.html

先ほど、'ownership'がRustでの重要なコンセプトだと述べました。
Rustでは、`x`はベクタを'所有(own)'しているといいます。
つまり、`x`がスコープを抜けると、ベクタのメモリはデアロケートされます。
これは、Rustのコンパイラによる静的な解析に基づいて行われ、ガベージコレクションの様な機構は用いられません。
つまり、Rustでは、`malloc`や`free`の様な関数を呼ぶ必要はありません。
人間は失敗をする物ですが、コンパイラは失敗しません。

先ほどの例に次の行を足しましょう。

```rust
fn main() {
    let mut x = vec!["Hello", "world"];

    let y = &x[0];
}
```

新たな変数束縛、`y`を導入しました。
この場合、`y`はベクタ`x`の最初の要素`x[0]`に対する'参照(reference)'です。
Rustの参照は他の言語のポインタに似ていますが、コンパイル時の安全性チェックが追加されています。
参照は、参照している変数を所有するのではなく、['借用(borrow)'][borrowing]します。
参照がスコープの外に出ても、この参照が借用している変数はデアロケートされません。
もしそうでなければ、二重デアロケートが起きる可能性があります。

[borrowing]: referencees-and-borrowing.html

三行目を足しましょう。
一見問題無い様に見えますが、コンパイルエラーになります。

```rust,ignore
fn main() {
    let mut x = vec!["Hello", "world"];

    let y = &x[0];

    x.push("foo");
}
```

`push`はベクタの最後尾に要素を追加するメソッドです。
このプログラムをコンパイルしようとすると、次のエラーを得ます。

```text
error: cannot borrow `x` as mutable because it is also borrowed as immutable
    x.push("foo");
    ^
note: previous borrow of `x` occurs here; the immutable borrow prevents
subsequent moves or mutable borrows of `x` until the borrow ends
    let y = &x[0];
             ^
note: previous borrow ends here
fn main() {

}
^
```

Rustコンパイラは、様々な詳細なエラーを出力します。
このエラーが説明している通り、先ほどの例では、mutableな変数束縛を作りましたが、それだけでは`push`できません。
なぜなら、すでにベクタの要素に対する参照`y`が作られているからです。
他の参照が存在しているときに、変更操作を加えるのは危険です。
たとえばこの例では、ベクタは2つの要素分のスペースしか最初にアロケートしません。
3つ目の要素のスペースをアロケートしようとすると、2つの要素の後ろに3つ目の要素分のスペースがあるとは限らないので、3つの要素分のスペースを新たにアロケートし、要素をコピーするかもしれません。
この場合、参照`y`は、古いスペースの要素を指したままですので、これは'dangling pointer'となります。
この`y`に対するいかなる操作も不正ですので、コンパイラはこれを検出します。

それでは、どの様にして解決するのでしょうか。
これには、主に2つの方法があります。
1つ目は、参照を作るのではなく、コピーを作ります。

```rust
fn main() {
    let mut x = vec!["Hello", "world"];

    let y = x[0].clone();

    x.push("foo");
}
```

Rustでは、デフォルトで[move semantics][move]を用います。
ですので、ムーブではなくコピーするためには、`clone()`メソッドを呼び出します。
この例では、`y`は参照ではなく、コピーされた値、`"Hello"`です。
ベクタの要素に対する参照を持っていないので、`push()`する事が出来ます。

[move]: ownership.html#move-semantics

もし、参照をどうしても持ちたいのならば、変更操作を加える前に、参照がスコープを抜けるようにします。

```rust
fn main() {
    let mut x = vec!["Hello", "world"];

    {
      let y = &x[0];
    }

    x.push("foo");
}
```

ここでは内部スコープを作り、`y`を内部スコープ内に閉じ込めました。

ownershipのコンセプトはダングリングポイントを防ぐだけでなく、不正なイテレータや平行性の問題等にも有効です。
