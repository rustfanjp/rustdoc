% Hello, Cargo!

[Cargo][cratesio]は、RustaceansがRustプロジェクトを管理するために使うツールです。
Cargoは今の所、バージョン1.0未満で、まだまだ開発中の状態です。
しかしながら、多くのRustプロジェクトを管理するためにはすでに十分ですので、Rustプロジェクトは最初からCargoを使う事を想定されています。

[cratesio]: http://doc.crates.io

Cargoは3つの事を行います。
コードのビルド、依存パッケージのダウンロード、依存パッケージのビルドです。
まずは、依存性を持たないプログラムを扱い、後から依存性を追加します。
Cargoでは、後から依存性を追加するのも非常に容易です。

もし、Rustを公式のインストーラから導入した場合、Cargoも導入されています。
他の方法でRustを導入した場合、[Cargo README][cargoreadme]を確認して下さい。

[cargoreadme]: https://github.com/rust-lang/cargo#installing-cargo-from-nightlies

## Cargoへの変換

それでは、Hello WorldプログラムをCargoへと変換しましょう。

私たちのプロジェクトをCargo化するには3つの事が必要です。
1、`Cargo.toml`設定ファイルを作る。
2、ソースファイルを適切に配置する。
3、古い実行ファイルを除去する(ここでは`main`や`main.exe`の事です）。

``` bash
$ mkdir src
$ mv main.rs src/main.rs
$ rm main # or 'rm main.exe' on Windows
```

> ノート: ここでは実行ファイルを作るので、ソースファイル名を`main.rs`としました。
> もし、ライブラリを作るならば、`lib.rs`の方が好ましいです。
> この様な命名規則はCargoによっても使用されますが、TOMLファイルの[`[lib]`か`[bin]`][crates-cutom]キーを設定する事で規則をオーバーライドできます。

[crates-custom]: http//doc.crates.io/manifest.html#configuring-a-taraget

Cargoは、ソースファイルが`src`ディレクトリ内にあると想定しています。
そのため、トップレベルディレクトリはREADMEやライセンスの配置の様な、他の用途のために使えます。
Cargoはプロジェクトを整然と保ちます。
何事にもそれ相応の置くべき場所があるものです。

次は、設定ファイルです。

```bash
$ editor Cargo.toml # or 'notepad Cargo.toml' on Windows
```

設定ファイル名はまさにこの通りにして下さい。
つまり、先頭は大文字の`C`です!

次の様に記述して下さい。

```toml
[package]

name = "hello_world"
version = "0.0.1"
authors = [ "Your name <you@example.com>"]
```

このファイルは[TOML](toml)形式です。
TOMLファイルはINIファイルに似ていますが、いくつかの点でより優れています。
TOMLのドキュメントには以下の様に有ります。

> TOMLは、意味論的に明らかで可読性の高い、コンパクトな設定ファイル形式である事を目標としています。
> TOMLは、曖昧さ無く、ハッシュテーブルへとマップできる様、デザインされています。
> TOMLは、様々な言語の中で使われているデータ構造に簡単にパースできます。


[toml]: https://github.com//toml-lang/toml

(訳注): TOMLはRustやCargoとは独立した、設定ファイルのための一般的なフォーマットです。
日本語で[仕様](https://github.com/toml-lang/toml/blob/master/versions/ja/toml-v0.4.0.md)を読む事も出来ます。

この設定ファイルをプロジェクトのルートディレクトリに置きさえすれば、ビルドの準備はできました。
次のコマンドを実行して下さい。

```bash
$ cargo build
   Compiling hello_world v0.0.1 (file:///home/yourname/projects/hello_world)
$ ./target/debug/hello_world
Hello, world!
```

やりました！
ここで、`cargo build`でプロジェクトをビルドし、`./target/debug/hello_world`でプログラムを実行しました。
`cargo run`する事で、これらを同時に行えます。

```bash
$ cargo run
     Running `target/debug/hello_world`
Hello, world!
```

今回は、プロジェクトを再ビルドしなかった事に注意してください。
Cargoはソースファイルに変更が加えられていない事を看破したので、再ビルドせずに、すでに存在するバイナリを実行しました。
もし、なんらかの変更をソースファイルに加えていた場合は次の様になります。

```bash
$ cargo run
   Compiling hello_world v0.0.1 (file:///home/yourname/projects/hello_world)
     Running `target/debug/hello_world`
Hello, world!
```

今回の例では、これは`rustc`よりも大きく優れている事はありませんが、将来の事を考えてみてください。
プロジェクトが複雑になってくると、コンパイルを正しく行うためにより多くの事をやる必要が有ります。
Cargoが有れば、たとえプロジェクトが成長しても、`cargo build`だけで全てを行えます。

プロジェクトのリリースの準備が整ったら、`cargo build --release`によって、最適化を伴ったコンパイルを行えます。

また、Cargoが`Cargo.lock`という新しいファイルを作成している事にも気付くでしょう。

```toml
[root]
name = "hello_world"
version = "0.0.1"
```

`Cargo.lock`は、Cargoがアプリケーションの依存性を追跡するために用います。
今のところは依存性が全く無いため、ファイルはスカスカです。
私たちはこのファイルを操作する必要は有りません。
Cargoにまかせておきましょう。

以上で終わりです！
私たちは`Cargo`によって、`hello_world`プロジェクトのビルドに成功しました。
このプログラムはシンプルですが、このやり方は、残りのRust人生の間中役に立つでしょう。
どんなRustプロジェクトでもこのやり方は通用すると思って良いでしょう。

```bash
$ git clone someurl.com/someproject
$ cd someproject
$ cargo build
```

## A New Project

新しいプロジェクトを作るたびに、同じ操作をする必要はありません！
Cargoは、ベアボーンなプロジェクトディレクトリを作り、すぐに開発を始められます。

プロジェクトをはじめるには、`cargo new`を使います。

```bash
$ cargo new hello_world --bin
```

`--bin`を渡す事で、ライブラリではなくアプリケーションを作ります。
実行可能なアプリケーションは'バイナリ'とも呼ばれます。

Cargoが何を生成したか見てみましょう。

```bash
$ cd hello_world
$ tree .
.
├── Cargo.toml
└── src
    └── main.rs

1 directory, 2 files
```

もし、`tree`コマンドがなければ、ディストリビューションのパッケージマネージャから入手して下さい。
必ずしも必要では有りませんが、絶対に役に立ちます。

これが、プロジェクトを始めるのに必要な全てです。
`Cargo.toml`を見てみましょう。

```toml
[package]

name = "hello_world"
version = "0.1.0"
authors = ["Your Name <you@example.com>"]
```

Cargoは、`git`のグローバル設定から、プロジェクトのデフォルト設定を推定します。
Cargoは、`hello_world`ディレクトリを`git`レポジトリとしても初期化しています。

`src/main.rs`ファイルを見てみます。

```rust
fn main() {
    println!("Hello, world!");
}
```

Cargoは、"Hello World!"プログラムを初期生成するので、直ぐにコーディングを開始できます。
Cargoのより深い理解にはCargoの[ガイド][guide]を参照してください。

[guide]: http://doc.crates.io/guide.html

ツールについては以上です。
次に、プログラミング言語Rust自身について学びましょう。

ここから先は、2つの道があります。
1、'[Learn Rust][learnrust]'でプロジェクトを開始する(トップダウン)。
2、'[Syntax andSsemantics][syntax]'で、言語そのものについて詳細に学ぶ(ボトムアップ)。
システムプログラミングについて経験がある人は1から始めるのが良いかもしれません。
動的言語から来た人は、どちらから始めても楽しめるでしょう。
学び方は人それぞれです！

[learnrust]: learn-rust.html
[syntax]: syntax-and-semantics.html

