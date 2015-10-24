% Generic functions

#### Generic functions

_ジェネリック関数(generic function)_ は、1個以上の _型仮引数(type parameter)_ をシグネチャに持ちます。
それぞれの型仮引数は、関数名の直後に、角括弧で囲み、コンマ区切りのリストで明示的に記述する必要があります。

```rust
// foo is generic over A and B

fn foo<A, B>(x: A, y: B) {
```

関数のシグネチャと本体の内側では、型仮引数の名前は、型名として扱う事ができます。
[トレイト(trait)][traits]束縛によって型仮引数がそのトレイトを使ってメソッド呼び出し出来ます。
トレイト束縛は、`where`文法によって指定できます。

[traits]: traits.html

```rust
fn foo<T>(x: T) where T: Debug {
```

ジェネリック関数が参照されると、参照された文脈によって型がインスタンス化されます。
例えば、`foo`関数を呼び出してみます。

```rust
use std::fmt::Debug;

fn foo<T>(x: &[T]) where T: Debug {
    // details elided
    # ()
}

foo(&[1, 2]);
```

この場合、型仮引数`T`を`i32`としてインスタンス化しています。

[パス(path)][paths]を指定する事で、型実引数を指定する事もできます。
これは、通常の関数呼び出しの文法では、型実引数を決定できない場合に用いられます。

[paths]: paths.html

`mem::size_of::<u32>() == 4`
