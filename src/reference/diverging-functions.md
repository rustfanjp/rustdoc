% Diverging functions

#### Diverging functions

関数宣言において、本来、返値型が現れる場所に`!`が現れた場合、これは特別な関数です。
以下の様な物です。

```
fn my_err(s: &str) -> ! {
    println!("{}", s);
    panic!();
}
```

この様な関数を"分岐(diverging)"と呼び、分岐関数は呼び出し元に値を返しません。

分岐関数のコードパスは`panic!()`か他の分岐関数呼び出しで終わります。
`!`は型情報を示している分けでは有りません。

全ての関数呼び出しのコードパスは[リターン式(return expression)][return-expression]か、分岐式で終わる必要があるので、分岐関数がしばしば必要になります。
例えば、次の例を見てください。

```
# fn my_err(s: &str) -> ! { panic!() }

fn f(i: i32) -> i32 {
   if i == 42 {
     return 42;
   }
   else {
     my_err("Bad number!");
   }
}
```

この例において、もし、`my_err`分岐関数に`!`が無く通常の関数であったとします。
この時、`f(i32) -> i32`関数の`else`分岐では、`i32`型の値を返さないコードパスが存在します。
これは、`f`の返値型`i32`と矛盾するので、型チェックに失敗します。
一方、分岐関数は最終的には`panic!()`に辿り着いて、通常とは異なるコードパスに飛ぶので、値を返す必要は有りません。

[reutrn-expression]: return-expression.html
