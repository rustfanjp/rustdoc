% Guessing Game

これから始めるプロジェクトでは、古典的な'数当てゲーム'を実装します。
このプログラムでは、1から100までの乱数を生成し、ユーザーに推測値を入力させます。
ユーザーが入力したら、その数が小さすぎるか大きすぎるかを伝えます。
もし、正しく推測できていた場合は、勝利画面を表示します。
面白そうですよね？

# Set up

それでは新しいプロジェクトを始めます。
プロジェクトディレクトリに移動して下さい。
どの様にディレクトリ構造を作り、どの様に`hello_world`のための`Cargo.toml`を作ったか覚えていますか？
Cargoはそのためのコマンドを持っているのでした。
次の様に入力して下さい。

```bash
$ cd ~/projects
$ cargo new guessing_game --bin
$ cd guessing_game
```

ここでは、プロジェクトの名前を`cargo new`に渡し、`--bin`フラグを付けました。
今はライブラリではなくバイナリを作ろうとしているのです。

生成された`Cargo.toml`を見てみましょう。

```toml
[package]

name = "guessing_game"
version = "0.1.0"
authors = ["Your Name <you@example.com>"]
```

Cargoはあなたの環境からこれらの情報を推定しています。
もしこれが正しくなければ、修正して下さい。

最後に、Cargoは'Hello, world!'を生成しました。
`src/main.rs`を見てみましょう。

```rust
fn main() {
    println!("Hello, world!");
}
```

Cargoが生成した物をコンパイルしてみましょう。

```bash
$ cargo build
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
```

エクセレント！
もう一度、`src/main.rs`を開いてください。
全てのコードはこのファイルに記述します。

コードに移る前に、もう一つのCargoコマンドを確認しておきましょう。
`cargo run`は、`cargo build`に似ていますが、生成されたバイナリを自動的に実行します。
やってみましょう。

```bash
$ cargo run
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
     Running `target/debug/guessing_game`
Hello, world!
```

グレート！
`cargo run`コマンドは、何度もプロジェクトを実行しなければならない時に便利です。
このゲームも正にその様なプロジェクトで、次のステップへ、次のステップへと素早く確認する必要があります。

# Processing a Guess

それでは始めましょう！
最初にやらなければならないのは、プレイヤーに数を入力させる事です。
次の様に`src/main.rs`に記述して下さい。

```rust
use std::io;

fn main() {
    println!("Guess the number!");

    println!("Please input your guess.");

    let mut guess = String::new();

    io::stdin().read_line(&mut guess)
        .ok()
        .expect("Failed to read line");

    println!("You guessed: {}", guess);
}
```

なんだか色々ありますね！
少しずつ見ていきましょう。

```rust
use std::io;
```

このプログラムでは、ユーザーの入力や結果の出力を扱う必要があります。
そのために、標準ライブラリの`io`ライブラリを使う必要があります。
Rustはデフォルトではほんの少しの物しかインポートしません([the 'prelude'][prelude])。
もし、preludeの中に必要な物が無ければ、直接`use`する必要があります。

[prelude]: ../std/prelude/index.html

```rust
fn main() {
```

以前見たように、`main()`関数はプログラムが始まる地点（エントリーポイント)です。
`fn`という文法は、新しい関数を宣言します。
`()`は、引数が無い事を表し、`{`と共に関数の本体が始まります。
返値の型を指定していないので、Rustは返値の型は`()`という空の[tuple][tuples]だと推定します。

[tuples]: primitive-types.html#tuples

```rust
    println!("Guess the number!");

    println!("Please input your guess.");
```

以前に、`println!()`は、[文字列(string)][strings]を画面に表示する[マクロ(macro)][macros]だと学びました。

[macros]: macros.html
[strings]: strings.html

```rust
    let mut guess = String::new();
```
これは興味深いですね！
このたった1行で多くの事を行っています。
まず、目に着くのは、[let文(statement)][let]で、'変数束縛(variable binsings)'を作っています。
仮に、次の様な形式だとします。

```rust
let foo = bar;
```

[let]: variable-bindings.html

これは、`foo`という名前で、`bar`の値に束縛された変数束縛を作成しています。
多くのプログラミング言語では、これは単に'変数'と呼ばれますが、Rustの変数束縛にはいくつか重要な違いがあります。

例えば、Rustの変数束縛はデフォルトで[immutable][immutable]です。
そのため、この例では`mut`を使って、変数束縛をmutableにしています。
実際には、`let`文の左辺には名前では無く、'[パターン(pattern)][patterns]'が来ます。
後ほど、パターンも使います。

```rust
let foo = 5; // immutable.
let mut bar = 5; // mutable
```

[immutable]: mutability.html
[patterns]: patterns.html

あ、そういえば、`//`はコメントの始まりを意味し、コメントは行末まで続きます。
Rustは[コメント(comments)][comments]のあらゆる文字を無視します。

[comments]: comments.html

そして、`let mut guess`は、`guess`という名前のmutableな変数束縛を導入します。
そこで、`=`の右側を見て、何が束縛されるか見てみると、それは`String::new()`です。

`String`は文字列型で、標準ライブラリで提供されます。
[`String`][string]は、UTF8エンコーディングの可変文字列です。

[string]: ../std/string/struct.String.html

`::new()`という文法は`::`を使っていますが、これは特定の型の`付随関数(associated function)`です。
つまり、この関数は`String`のインスタンスでは無く、`String`型そのものに付随しています。
プログラミング言語によっては、この様な関数を`静的メソッド(static method)`と呼びます。

この関数は`new()`と名付けられていて、新しい空の`String`を作ります。
`new()`関数は、色々な型に存在しますが、`new`は、ある種の新しい'値'を作るための共通した関数です。

次に行きましょう。

```rust
    io::stdin().read_line(&mut guess)
        .ok()
        .expect("Failed to read line");
```

また色々でてきました！
1つずつ見て行きます。
1行目は2つの部分に分かれます。
これが1つ目の部分です。

```rust
io::stdin()
```

プログラムの最初の行で、`std::io`を`use`したのを覚えていますか？
ここでは、`std::io`の付随関数を呼び出しています。
もし、`use std::io`していなかったら、この行は、`std::io::stdin()`である必要が有ります。

この関数は、ターミナルの標準入力のハンドルを返します。
それはつまり、[std::io::Stdin][iostdin]です。

[iostdin]: ../std/io/struct.Stdin.html

次の部分は、このハンドルを使い、ユーザーの入力を受け付けています。

```rust
.read_line(&mut guess)
```

この行では、ハンドルの[`read_line()'][read_line]メソッドを呼び出しています。
[メソッド(methods)][method]は、付随関数に似ていますが、ある型のインスタンスに対して呼び出されます。
また、ここでは`read_line()`の引数として、`&mut guess`を渡しています。

[read_line]: ../std/io/struct.Stdin.html#method.read_line
[method]: method-syntax.html

`guess`をどの様に束縛したか覚えていますか?
しかしながら、`read_line`は、`String`ではなく、`&mut String`を引き数として取ります。
Rustは、'[参照(references)][references]'という機能を持っていますが、これによって、一つのデータに対して複数の参照を作り、コピーを減らす事が出来ます。
参照は複雑な機能ですが、Rustの大きな目玉で有り、安全で簡単に使う事が出来ます。
今の所はこの機能の詳細を知る必要は有りませんが、ここでは、`let`と同様に、参照はデフォルトでimmutableで有る事を覚えておいてください。
従って、`&guess`では無く、`&mut guess`と書く必要が有ります。

なぜ、`read_line()`は文字列のmutable参照を取っているのでしょうか？
この関数は、ユーザーの入力を読み取り、その値をメモリ上に配置する必要が有ります。
そのため、`read_line()`関数は、mutableな参照を必要とします。

[references]: references-and-borrowing.html

まだまだ、この行は終わっていません。
文字列としての行は終わっていますが、論理的にはこのこの表は次の様に続いています。

```rust
        .ok()
        .expect("Failed to read line");
```

`.foo()`によって、メソッドを呼び出すとき、改行や空白を挟んでも構いません。
これは、長い行を分割するのに役に立ちます。
また、次の様に一行に記述する事も出来ます。

```rust
    io::stdin().read_line(&mut guess).ok().expect("failed to read line");
```

しかしながら、この様な記述は可読性に劣ります。
ですので、3つのメソッド呼び出しを3つの行に分割しました。
`read_line()`については既に話しましたが、`ok()`や`expect()`についてはどうでしょうか？
`read_line()`は読み取った値を`&mut String`に格納しますが、`read_line()`自体の返値は、[`io::Result'][ioresult]です。
Rustの標準ライブラリには、`Result`という名前を持った方が沢山あります。

[ioresult]: ../std/io/type.Result.html
[result]: ../std/result/enum.Result.html

`Result`は、エラーハンドリングのための情報を格納しています。
`Result`型の値は、その型に定義されたメソッドを持っています。
`io::Result`の場合は、`ok()`メソッドを持っていて、「この値は正当だと考え、たとそうでなくても、エラーを無視しろ」という意味です。
なぜ、エラーを無視するのでしょうか？
基本的なプログラムでは、エラーをただ表示するだけで、復帰処理等を行うことなく、ただそれ以上プログラムを継続できません。
[`ok()][ok]メソッドは、`expect()`という別のメソッドが定義された値を返します。
[`expect()][expect]メソッドは、一つ値を取り、もし元のメソッドが失敗していた場合、メッセージと共に[`パニック(panic)`][panic]を起こし、プログラムはクラッシュします。

[ok]: ../std/result/enum.Result.html#method.ok
[expect]: ../std/option/enum.Option.html#method.expect
[panic]: error-handling.html

もしこれらの2つのメソッド(`ok()`と`expect()`)が使われなかった場合、コンパイラは警告を出します。

```bash
$ cargo build
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
src/main.rs:10:5: 10:39 warning: unused result which must be used,
#[warn(unused_must_use)] on by default
src/main.rs:10     io::stdin().read_line(&mut guess);
                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
```

Rustは、`Result`の値を使っていない事を警告します。
この警告は`io::Result`についての注釈に基づいています。
Rustは、対処すべきエラーに対処していない事を警告しようとします。
この警告を抑える正しい方法は、エラー処理を実際に書く事です。
幸いな事に、もしエラーが有ったい場合にクラッシュさせるには、この2つのメソッドで十分です。
もし、エラーからなんらかの方法で復帰するには、別の方法が必要ですが、それは後ほど扱います。

あとはこの1行だけです。

```rust
    println!("You guessed: {}", guess);
```

これは、保存したユーザーの入力を文字列として表示します。
`{}`はプレースホルダで、`guess`を引数として渡しています。
`{}`を複数回用いた場合は、その数だけ引数を渡す必要が有ります。

```rust
let x = 5;
let y = 10;

println!("x and y: {} and {}", x, y);
```

簡単ですね。

とにかく出来ました。
とりあえず、`cargo run`によって実行してみましょう。


```bash
$ cargo run
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
     Running `target/debug/guessing_game`
Guess the number!
Please input your guess.
6
You guessed: 6
```

素晴らしい！
これでキーボードから入力を受付、入力を表示するという最初の部分が出来ました。

# Generating a secret number

次に、秘密の数を生成する必要が有ります。
Rustは標準ライブラリには乱数生成機能を持っていません。
しかしながら、Rustチームは[`rand`][randcrate]クレートを提供しています。
`クレート(crate)`はRustコードのパッケージです。
私達は今、`バイナリクレート`を作っていますが、`rand`は`ライブラリクレート`で、ほかのプログラムから利用される事を意図しています。

[randcrate]: https://crates.io/crates/rand

外部クレートの利用こそ、Cargが活躍します。
`rand`を使うコードを書く前に、`Cargo.toml`を修正します。
最後尾に次の文を追加して下さい。

```toml
[dependencies]

rand="0.3.0"
```

`[dependencies]`セクションの後に書かれた物は、ほかのセクションが始まるまでは、`[dependencies]`セクションに属します。
依存性(dependencies)セクションは、あなたのプロジェクトがどの外部クレートのどのバージョンに依存しているかを示します。
今回は、`0.3.0`というバージョンを指定しましたが、Cargoは、このバージョンと互換性があるバージョンを選択します。
Cargoは[Semantic Versioning][semver]という標準的なバージョンの書き方を理解します。
もし、正確に`0.3.0`を選択したい場合は、`=0.3.0`と書くべきです。
もし、一番新しいバージョンを選択したい場合は、`*`を使う事も出来ます。
また、ある特定の範囲のバージョンを選択する事も出来ます。
詳しくは、[Cargoのドキュメント][cargodoc]を参照して下さい。

[semver]: http://semver.org
[cargodoc]: http://doc.crates.io/crates-io.html

(訳注) Cargoは、二つのバージョン`0.x.y`と`0.x.z`が`z > y`ならば互換性があると見做します。
いわゆる'メジャーバージョン'が1以上ならば、この様な規則は有りません。

今の所はこれ以上変更せずに、ビルドしてみましょう。

```bash
$ cargo build
    Updating registry `https://github.com/rust-lang/crates.io-index`
 Downloading rand v0.3.8
 Downloading libc v0.1.6
   Compiling libc v0.1.6
   Compiling rand v0.3.8
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
```

(もちろん、違うバージョンの数字が表示されるかもしれません。)

新たな出力がたくさん出てきました！
今や外部依存性があるので、Cargoはレジストリからあらゆるライブラリの最新バージョンをフェッチします。
これは、[Crates.io][cratesio]からデータをコピーします。
Crates.ioは、Rustのエコシステムであり、人々がRustのオープンソースプロジェクトを投稿しています。

[cratesio]: https://crates.io

レジストリをアップデートした後、Cargoは`[dependencies]`をチェックし、まだ持っていないライブラリをダウンロードします。
今回の場合、`rand`にしか依存していないはずですが、`libc`のコピーも入手しています。
これは、`rand`が`libc`に依存しているためです。
これらをダウンロードした後、ライブラリをコンパイルし、私達のプロジェクトをコンパイルします。

`cargo build`をもう一度走らせると、今までと違った出力が出ます。

```bash
$ cargo build
```

素晴らしい！
全く出力が有りません。
Cargoは、プロジェクトがビルド済みで、依存ライブラリもビルド済みで有る事を看破しています。
ですので、これ以上やる仕事は有りません。
もし、`src/main.rs`を再び開き、なんらかの変更を加えて保存し、ビルドすると次の様な出力を得ます。

```bash
$ cargo build
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
```

さて、今回例えば、`rand`のバージョン`0.3.8`がダウンロードされたとして、もし、次にコンパイルしようとした時に、バージョン`0.3.9`がダウンロードされるというのは有りそうな事です。
もし、`0.3.9`が重要なバグフィックスだが、私達のコードを壊すようなレグレッションを含んでいた場合はどうすれば良いでしょうか？

答えは、プロジェクト内の`Cargo.lock`ファイルに在ります。
Cargoは最初にプロジェクトをビルドした時に、[dependencies]の条件に合うバージョン全てを導出し、`Cargo.lock`ファイルにメモします。
次にビルドする時、Cargoはバージョンを導出し直す事なく、`Cargo.lock`ファイルを見てバージョンを選択します。
ですので、明示的にアップグレードしない限りは、Cargoは`0.3.8`を使おうとします。

それでは、`0.3.9`を_使いたい_時はどうすと良いでしょうか。
Cargoはそのために`update`というコマンドを持っています。
このコマンドを使うと、Cargoは`Cargo.lock`ファイルを無視し、レジストリをフェッチし直し、バージョンを再導出します。

(訳注) 今回の場合、`0.3.0`に互換性のあるバージョンは`0.3.x`ですので、`0.4.x`を使いたい場合は、`Cargo.toml`を書き換える必要が有ります。

[Cargo][docargo]やCargoの[エコシステム][doccratesio]についてはまだまだ色々ありますが、今の所はこれで十分でしょう。
Cargoはライブラリの再利用を本当に簡単にします。
ですので、Rustaceanたちは他のサブパッケージから、小さなプロジェクトを作る傾向が有ります。

[doccargo]: http://doc.crates.io
[doccratesio]: http://doc.crates.io/crates-io.html

それでは実際に`rand`を使ってみましょう。
これが次のステップです。

```rust
extern crate rand;

use std::io;
use rand::Rng;

fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    println!("The secret number is: {}", secret_number);

    println!("Please input your guess.");

    let mut guess = String::new();

    io::stdin().read_line(&mut guess)
        .ok()
        .expect("failed to read line");

    println!("You guessed: {}", guess);
}
```

最初の変更は、1行目です。
`extern crate rand`と書いてあります。
`rand`は`[dependencies]`の中で宣言したので、`extern crate`で、Rustに外部クレートで有る事を教えます。
これはまた、`use rand`と同様な働きもして、`rand::`と付ける事で、`rand`クレートの中の物を扱えます。

次に、また別の`use rand::Reg`という行を追加しました。
これから、あるメソッドを使うのですが、そのメソッドは`Rng`は今のスコープにある事を要求します。
基本的なアイデアこうなります。
メソッドは、'トレイト(traits)'と呼ばれる物に定義されています。
このメソッドを使うには、そのトレイトを今のスコープに持ってくる必要が有ります。
詳細は、[トレイト(traits)][traits]を参照して下さい。

[traits]: traits.html

さらに2つの行を足しました。

```rust
    let secret_number = rand::thread_rng().gen_range(1, 101);

    println!("The secret number is: {}", secret_number);
```

ここでは、`rand::thread_rng()`関数を使い、乱数生成器のコピーを得ました。
この乱数先制機は、このメソッドを実行した[スレッド(thread)][concurrency]内でローカルです。
`use rand::Reg`したので、この乱数生成器は、`gen_range()`メソッドを持っています。
このメソッドは乱数の範囲を指定する2つの引数を取ります。
下限は含み、上限は含みません。
ですので、1から100までを生成するには、`1`と`101`を渡せば良いです。

[concurrency]: concurrency.html

2行目は、秘密の数をプリントしています。
この関数は開発中においても非常に便利で、簡単に色々な事をテストできます。
しかしながら、リリースバーションではこの行は消すべきです。
もし、答える前に秘密の数がプレイヤーに分かってしまったら勝負になりません！

何度かプログラムを実行してみましょう。

```bash
$ cargo run
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
     Running `target/debug/guessing_game`
Guess the number!
The secret number is: 7
Please input your guess.
4
You guessed: 4
$ cargo run
     Running `target/debug/guessing_game`
Guess the number!
The secret number is: 83
Please input your guess.
5
You guessed: 5
```

素晴らしい！
次は、推測値と秘密の数を比較しましょう。

# Comparing guesses

さて、これまででユーザーの入力は受け付けました。
乱数とこれを比較してみましょう。
これだけではまだ動きませんが、これが次のステップです。

```rust
extern crate rand;

use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    println!("The secret number is: {}", secret_number);

    println!("Please input your guess.");

    let mut guess = String::new();

    io::stdin().read_line(&mut guess)
        .ok()
        .expect("failed to read line");

    println!("You guessed: {}", guess);

    match guess.cmp(&secret_number) {
        Ordering::Less    => println!("Too small!"),
        Ordering::Greater => println!("Too big!"),
        Ordering::Equal   => println!("You win!"),
    }
}
```

また色々出てきました。
まずは、また別の`use`で、`std::cmp::Ordering`型をこのスコープに導入しています。
そして、一番下に新たに5行追加されています。

```rust
match guess.cmp(&secret_number) {
    Ordering::Less    => println!("Too small!"),
    Ordering::Greater => println!("Too big!"),
    Ordering::Equal   => println!("You win!"),
}
```

`cmp()`メソッドは比較可能な物なら、何に対しても呼び出せます。
このメソッドは、比較したい物の参照を取ります。
このメソッドは、先ほど導入した`Ordering`型を返します。
ここでは、[`マッチング(match)`][match]文を使い、`Ordering`の型を決定しています。
`Ordering`は[列挙型(`enum`)][enum]で、たとえばこういった物です。

```rust
enum Foo {
    Bar,
    Baz,
}
```

[match]: match.html
[enum]: enums.html

この定義によって、`Foo`型の物は`Foo::Bar`か`Foo:Baz`になります。
`enum`型の値の名前空間を示すのに`::`を使いました。

[`Ordering`][ordering]列挙型は、`Less`、`Equal`、`Greater`の3つの値を持ちえます。
マッチング文はある型の値を取り、可能な値についての'腕(arm)'を作ります。
`Ordering`は3つの値が有り得るので、3つの腕を持ちます。

```rust
match guess.cmp(&secret_number) {
    Ordering::Less    => println!("Too small!"),
    Ordering::Greater => println!("Too big!"),
    Ordering::Equal   => println!("You win!"),
}
```

[ordering]: ../std/cmp/enum.Ordering.html

もし、比較の結果が`Less`ならば`Too small!`と表示し、`Greater`ならば`Too big!`と表示し、`Equal`なら、`You win!`と表示します。
マッチング文は本当に便利で、Rustでは良く用いられます。

先に述べた通り、このままでは上手く動きません。
ビルドしてみましょう。

```bash
$ cargo build
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
src/main.rs:28:21: 28:35 error: mismatched types:
 expected `&collections::string::String`,
    found `&_`
(expected struct `collections::string::String`,
    found integral variable) [E0308]
src/main.rs:28     match guess.cmp(&secret_number) {
                                   ^~~~~~~~~~~~~~
error: aborting due to previous error
Could not compile `guessing_game`.
```

わわわ！
エラーが出てきました。
重要な部分は`mismatched types`です。
Rustは型推論付きの強い静的型付けシステムを持っています。
`let guess = String:::new()`と書くと、Rustは`guess`が`String`型だと推論し、ユーザーが直接指定する必要は有りません。
`securet_number`についてですが、0から100までの数を表す事が出来る数値型は色々あります。
`i32`は32ビット符号付き整数ですし、`u32`は符号無し32ビット整数で、`i64`は64ビット符号付き整数等々です。
これまでは気にしませんでしたが、Rustはデフォルトで`i32`を整数型として使います。
しかしながら、Rustは`guess`(`String`型)と`securet_number`(`i32`型)をどう比較して良いか分かりません。
ですので、`String`型を数値に変換する必要が有ります。
そのためにはさらに3行必要です。

```rust
extern crate rand;

use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    println!("The secret number is: {}", secret_number);

    println!("Please input your guess.");

    let mut guess = String::new();

    io::stdin().read_line(&mut guess)
        .ok()
        .expect("failed to read line");

    let guess: u32 = guess.trim().parse()
        .ok()
        .expect("Please type a number!");

    println!("You guessed: {}", guess);

    match guess.cmp(&secret_number) {
        Ordering::Less    => println!("Too small!"),
        Ordering::Greater => println!("Too big!"),
        Ordering::Equal   => println!("You win!"),
    }
}
```
新しい3行はこれです。

```rust
    let guess: u32 = guess.trim().parse()
        .ok()
        .expect("Please type a number!");
```

ちょっとまって、`guess`は既に定義していませんでしたか？
はい、しかしながら、Rustは以前に定義した`guess`を'隠す'事を許しています。
これは、こういっった状況では良く使われます。
`guess`は最初`String`として定義されましたが、これを`u32`型に変換したいと思います。
束縛名を隠す事によって、`guess_str`のような冗長な名前を使わずに済みます。
`guess`には先ほど書いた式を束縛します。

```rust
guess.trim().parse()
```

`ok().expect()`呼び出しを伴っています。
ここでは、`guess`は古い`String`型の`guess`を意味しています。
`String`型に対する`trim()`メソッドは、先頭と末尾の連続する空白を除去します。
これは重要です。
`read_line()`に入力するには'return'を最後に入力する事になりますが、例えば、`5`と入力して、'return'した場合、`guess`は`5\n`となります。
`\n`は改行文字ですが、`trim()`メソッドはこれを除去し、文字列をただ`5`とします。
`String`型に対する[`parse()`][parse]メソッドは、文字列を何らかの他の型に変換します。
この型を指定するために、`let guess: u32`とし、`guess`直後のコロン(`:`)の後に`guess`の型を指定します。
ここでは、`u32`の32ビット符号無し整数として指定しています。
Rustはいくつかの[ビルトイン数値型][number]を持ちますが、ここでは`u32`を選択しました。
これは、小さな正数としては良い選択です。

[parse]: ../std/primitive.str.html#method.parse
[number]: primitive-types.html#numeric-types

`read_line()`の様に、`parse()`は失敗するかもしれません。
例えば、`A👍%`の様な文字列の場合はどうでしょうか？
この様な場合、整数に変換する事は出来ないので、`read_line()`と同様に、`ok()`と`expect()`を使って、失敗した場合はクラッシュさせます。

プログラムを試してみましょう！

```bash
$ cargo run
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
     Running `target/guessing_game`
Guess the number!
The secret number is: 58
Please input your guess.
  76
You guessed: 76
Too big!
```

素晴らしい！
ここでは、わざと入力の前にスペースを追加しましたが、正しく数値を読み取っています。
何度かプログラムを走らせ、ゲームが正しく動く事を確認してみましょう。

さて、ゲームはとりあえず動きますが、一度しかゲームできません。
ループを追加してみましょう。

# Looping

`loop`キーワードは、無限ループを意味します。

```rust
extern crate rand;

use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    println!("The secret number is: {}", secret_number);

    loop {
        println!("Please input your guess.");

        let mut guess = String::new();

        io::stdin().read_line(&mut guess)
            .ok()
            .expect("failed to read line");

        let guess: u32 = guess.trim().parse()
            .ok()
            .expect("Please type a number!");

        println!("You guessed: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less    => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal   => println!("You win!"),
        }
    }
}
```

そして、試してみましょう。
ところで、本当に無限ループを追加した事になっているのでしょうか？
`parse()`について議論した事を覚えていますか？
もし、数でない答えを入力すると、`return`し、終了します。

```bash
$ cargo run
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
     Running `target/guessing_game`
Guess the number!
The secret number is: 59
Please input your guess.
45
You guessed: 45
Too small!
Please input your guess.
60
You guessed: 60
Too big!
Please input your guess.
59
You guessed: 59
You win!
Please input your guess.
quit
thread '<main>' panicked at 'Please type a number!'
```

はっ！
`quit`と入力したら、本当にquitしてしまいました。
もちろんこれは、他のどんな数でない入力でも同様ですが。
これだけでは、最低限の機能しか有りません。
ゲームに勝利したら、本当に終了する様にしてみましょう。

```rust
extern crate rand;

use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    println!("The secret number is: {}", secret_number);

    loop {
        println!("Please input your guess.");

        let mut guess = String::new();

        io::stdin().read_line(&mut guess)
            .ok()
            .expect("failed to read line");

        let guess: u32 = guess.trim().parse()
            .ok()
            .expect("Please type a number!");

        println!("You guessed: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less    => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal   => {
                println!("You win!");
                break;
            }
        }
    }
}
```

`You win!`の後に`break`行を追加する事で、ループを脱出します。
ループは`main()`最後に有るので、ループからの脱出はプログラムの終了を意味します。
もう一工夫してみましょう。
例えば、数でない入力が有った時に、終了するのではなく、それを無視するようにしてみましょう。

```rust
extern crate rand;

use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    println!("The secret number is: {}", secret_number);

    loop {
        println!("Please input your guess.");

        let mut guess = String::new();

        io::stdin().read_line(&mut guess)
            .ok()
            .expect("failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You guessed: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less    => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal   => {
                println!("You win!");
                break;
            }
        }
    }
}
```

これが変更した行です。

```rust
let guess: u32 = match guess.trim().parse() {
    Ok(num) => num,
    Err(_) => continue,
};
```
これは、'エラー即クラッシュ'から'エラーハンドリング'への進化です。
`ok().expect()`から`match`文へと変更しています。
`parse()`によって返された`Result`は`Rrdering`と同様に列挙型です。
`Result`の場合は、成功すれば`Ok`を返し、失敗すれば`Err`を返します。
それぞれの値はさらに情報を持っています。
パースされた整数か、エラー型です。
この場合、`Ok(num)`というマッチは、`Ok`の内部の値を`num`に束縛し`num`を返します。
`Err`の場合は、どんな型か気にしないので、名前では無く`_`を使っています。
エラーを無視し、`continue`は、`loop`の次の繰り返しを開始します。

良さそうですね！
試してみましょう。

```bash
$ cargo run
   Compiling guessing_game v0.1.0 (file:///home/you/projects/guessing_game)
     Running `target/guessing_game`
Guess the number!
The secret number is: 61
Please input your guess.
10
You guessed: 10
Too small!
Please input your guess.
99
You guessed: 99
Too big!
Please input your guess.
foo
Please input your guess.
61
You guessed: 61
You win!
```

素晴らしい！
ちょっと工夫でゲームを完成させました。
何か忘れていませんか？
そうです、秘密の数を表示するべきではありませんね。
テストのためには良いですが、ゲームをぶち壊しにしてしまいます。

```rust
extern crate rand;

use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    loop {
        println!("Please input your guess.");

        let mut guess = String::new();

        io::stdin().read_line(&mut guess)
            .ok()
            .expect("failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You guessed: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less    => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal   => {
                println!("You win!");
                break;
            }
        }
    }
}
```

# Complete!

この時点で、あなたは数当てゲームを完成させました！
おめでとう！

このプロジェクトは、`let`、`match`、メソッド、付随関数、外部クレート等々、多くの要素が有りました。
次のプロジェクトはさらに多くの物が表れますよ！
