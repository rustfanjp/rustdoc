% Lifetimes

このガイドでは、Rustのオーナーシップ(ownership)システムの一つについて解説します。
これは、Rustの開発者が必ず学ぶベき事項です。
オーナーシップによって、Rustはメモリ安全性という偉大な目標を達成しています。
オーナシップには以下の様な異なる概念が有ります。

* [オーナーシップ(ownership)][ownership]、基本のコンセプト。
* [ボローイングborrowing][borrowing]、'参照(reference)'。
* 寿命(lifetime)、今読んでいるこれ。

これらの3つのチャプターは互いに関連しています。
これら全てを必ず理解して下さい。

[ownership]: ownership.html
[borrowing]: references-and-borrowing.html

# Meta

詳細に行く前に、オーナーシップの重要性について学びましょう。

Rustは安全性と速度の両立に注目しています。
Rustは'ゼロコスト抽象化'によってこれを達成しています。
つまり、Rustでは抽象化に伴うコストを可能な限り最小化しています。
オーナーシップシステムはゼロコスト抽象化の主な例です。
ここで話す様々な解析は、 _コンパイル時_ に行われます。
ですので、実行時コストについては心配する必要は有りません。

(訳注) 実際には、安全性要件を満たすために記述できないコードが有るので、(手動/自動)最適化に制約が有ります。
逆に、安全性要件を不変条件としてアグレッシブな最適化ができる可能性もあります。

しかし、オーナーシップシステムにはある種のコストが有ります。
すなわち、学習コストです。
多くのRust新規ユーザーは、"ボローチェッカー恐怖症"を経験します。
つまり一見ユーザーが正しいと信じているコードが、コンパイラによって拒絶されるのです。
これはしばしば、プログラマのオーナーシップについてのメンタルモデルがRustシステムのオーナーシップと異なるためだと考えられます。
良いニュースもあります！
多くの経験を積んだRUstユーザーは、一度オーナーシップシステムになれると、ボロチェッカーに手間取る事は無くなると言います。

これを胸に留めて、寿命について学んでみましょう。

# Lifetimes

あるリソースに対する参照を、他の者に貸し出すというのは、しばしば複雑なプロセスです。
例えば次の例を考えてみます。

- あるリソースのハンドルを取得(acquire)する。
- リソースに対する参照を、誰かに貸す。
- リソースをデアロケートする。どこかの誰かはまだ参照を持っている。
- その誰かはリソースを使い続ける。

あらら！
誰かさんの参照は不正なリソースを指しています。
これはダングリングポインタや'use after free'と呼ばれます。

これを防ぐには、ステップ3の後に、ステップ4が起きないようにしなければなりません。
Rustのオーナーシップシステムは寿命システムによって達成します。
寿命はある参照があるスコープ内で有効かどうかを決定します。

もし関数が参照を引数として場合、寿命は暗黙的か明示的に指定されます。

```rust
// implicit
fn foo(x: &i32) {
}

// explicit
fn bar<'a>(x: &'a i32) {
}
```

`a`は、'寿命a'と読みます。
_全て_ の参照は寿命を持ちます。
しばしば、寿命指定は省略できます。
次の部分を見てみましょう。

```rust
fn bar<'a>(...)
```

この部分は寿命を宣言しています。
これは、`bar`は、1つの寿命`'a`を持つ、という意味です。
もし、2つの参照変数を持っていた場合、次の様に書きます。

```rust
fn bar<'a, 'b>(...)
```

引数リストで、名前を付けた寿命を使っています。

```rust
...(x: &'a i32)
```

`&mut`参照の場合は次の様にします。

```rust
...(x: &'a mut i32)
```

`&mut i32`と`&'a mut i32`を比べると、これらはほぼ同じですが、`'a`が `&`と`mut i32`の間に割り込んでいます。
`'a`は、寿命`'a`のミュータブル参照という意味です。

# In `struct`s

[構造体(struct)][structs]に対しても、明示的な寿命指定が必要です。

```rust
struct Foo<'a> {
    x: &'a i32,
}

fn main() {
    let y = &5; // this is the same as `let _y = 5; let y = &_y;`
    let f = Foo { x: y };

    println!("{}", f.x);
}
```

[structs]: structs.html

みてわかる通り、この構造体は寿命を持っています。

```rust
struct Foo<'a> {
# x: &'a i32,
# }
```

なぜここで寿命が必要なのでしょうか？
寿命によって、参照`x`が`Foo`よりも長く生きる事が出来ない様にしています。

## `impl` blocks
`Foo`にメソッドを実装してみましょう。

```rust
struct Foo<'a> {
    x: &'a i32,
}

impl<'a> Foo<'a> {
    fn x(&self) -> &'a i32 { self.x }
}

fn main() {
    let y = &5; // this is the same as `let _y = 5; let y = &_y;`
    let f = Foo { x: y };

    println!("x is: {}", f.x());
}
```

この様に、`impl`内で、`Foo`に対する寿命を宣言する必要があります。
そこで、今回は`impl`に対して寿命を宣言し、`Foo`に対してその寿命を指定しています。

## Multiple lifetimes

複数の参照を持っている場合、同じ寿命を使えます。

```rust
fn x_or_y<'a>(x: &'a str, y: &'a str) -> &'a str {
#    x
# }
```

これは、`x`と`y`が同じスコープ内で生きていて、死ぬ時は同時に死ぬ事を意味しています。
返値も同じスコープ内まで生きています。
もし、`x`と`y`に違う寿命を持たせないのなら、複数の寿命を宣言出来ます。

```rust
fn x_or_y<'a, 'b>(x: &'a str, y: &'b str) -> &'a str {
#    x
# }
```

この例でぇあ、`x`と`y`は異なる有効なスコープを持っています。
しかしながら、返値の寿命は`x`までです。

## Thinking in scopes

スコープを視覚化する事で寿命の見通しが良くなります。

```rust
fn main() {
    let y = &5;     // -+ y goes into scope
                    //  |
    // stuff        //  |
                    //  |
}                   // -+ y goes out of scope
```

`Foo`を追加します。

```rust
struct Foo<'a> {
    x: &'a i32,
}

fn main() {
    let y = &5;           // -+ y goes into scope
    let f = Foo { x: y }; // -+ f goes into scope
    // stuff              //  |
                          //  |
}                         // -+ f and y go out of scope
```

`f`は`y`のスコープ内で生きているので、これはコンパイル可能です。
もし、そうでないと、コンパイルできません。

```rust
struct Foo<'a> {
    x: &'a i32,
}

fn main() {
    let x;                    // -+ x goes into scope
                              //  |
    {                         //  |
        let y = &5;           // ---+ y goes into scope
        let f = Foo { x: y }; // ---+ f goes into scope
        x = &f.x;             //  | | error here
    }                         // ---+ f and y go out of scope
                              //  |
    println!("{}", x);        //  |
}                             // -+ x goes out of scope
```

わお！
`f`と`y`のスコープは、`x`のスコープよりも狭いです。
しかし、`x = &f.x`によって`x`はすでに死んでいるスコープを参照してしまいます。

名前付き寿命は、これらのスコープに名前を与える方法です。

## 'static

'static'と名付けられた寿命は、特別な寿命です。
これは、寿命がプログラム全体で続く事を示します。
多くのプログラマは、文字列を扱う時に`'static`寿命に出会います。

```rust
let x: &'static str = "Hello, world.";
```

文字列リテラルは`&'static str`型です。
なぜなら参照は常に生きているからです。
この本体は、最終的にはバイナリのデータセグメントに埋め込まれます。
他にはグローバルなオブジェクトも`'static`寿命を持ちます。

```rust
static FOO: i32 = 5;
let x: &'static i32 = &FOO;
```

これは、1つの`i32`をデータセグメントに追加します。
`x`はグローバルなオブジェクトに対する参照なので`'static`寿命を持てます。

## Lifetime Elision

Rustは関数本体の中等では協力な型推論機構を持っています。
しかしながら、アイテムシグネチャの中では型推論を禁止しています。
ただし、これにも例外が有り、関数シグネチャの中では"寿命省略(lifetime elision)"というアルゴリズムによって型推論を行います。
寿命省略は関数シグネチャのみに基づいて行われ、関数本体に対しては考慮されません。
寿命省略は簡単明快な規則で、普通の型推論の様に、実際の型を隠しはしません。

これから、 *入力寿命(input lifetime)* と *出力寿命(output lifetime)* という用語を使います。
入力寿命は、関数のパラメタの寿命で、出力寿命は、返値の寿命です。
例えば、この関数は入力寿命を持っています。

```rustr
fn foo<'a>(bar: &'a str)
```

次の例は出力寿命を持ちます。

```rust
fn foo<'a>() -> &'a str
```

次の例は、入力寿命と出力寿命両方を持ちます。

```rust
fn foo<'a>(bar: &'a str) -> &'a str
```

入力寿命と出力寿命について3つの規則があります。

* 関数の実引数のそれぞれの寿命が省略されると、新たな寿命を持った引数となります。

* 入力寿命が1つある場合、省略されているかどうかの依らず、出力寿命の省略された寿命はこの入力寿命になります。

* もし複数の入力寿命が有り、ひとつが`&self`か`&mut self`の時、出力変数の省略された寿命は`self`の寿命となります。

そうでなければ、出力寿命を省略するのはエラーです。

### Examples

Here are some examples of functions with elided lifetimes.  We’ve paired each
example of an elided lifetime with its expanded form.

```rust,ignore
fn print(s: &str); // elided
fn print<'a>(s: &'a str); // expanded

fn debug(lvl: u32, s: &str); // elided
fn debug<'a>(lvl: u32, s: &'a str); // expanded

// In the preceding example, `lvl` doesn’t need a lifetime because it’s not a
// reference (`&`). Only things relating to references (such as a `struct`
// which contains a reference) need lifetimes.

fn substr(s: &str, until: u32) -> &str; // elided
fn substr<'a>(s: &'a str, until: u32) -> &'a str; // expanded

fn get_str() -> &str; // ILLEGAL, no inputs

fn frob(s: &str, t: &str) -> &str; // ILLEGAL, two inputs
fn frob<'a, 'b>(s: &'a str, t: &'b str) -> &str; // Expanded: Output lifetime is ambiguous

fn get_mut(&mut self) -> &mut T; // elided
fn get_mut<'a>(&'a mut self) -> &'a mut T; // expanded

fn args<T:ToCStr>(&mut self, args: &[T]) -> &mut Command // elided
fn args<'a, 'b, T:ToCStr>(&'a mut self, args: &'b [T]) -> &'a mut Command // expanded

fn new(buf: &mut [u8]) -> BufWriter; // elided
fn new<'a>(buf: &'a mut [u8]) -> BufWriter<'a> // expanded
```
