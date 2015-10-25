% Lambda expressions

### Lambda expressions

_ラムダ式(lambda expression)_ は1つの式で、関数を定義しその関数を値として示します。
ラムダ式はパイプ記号(`|`)で区切られた式です。

ラムダ式は、`ident_list`によって表された仮引数のリストを式にマップします。
`ident_list`中の識別子(identifier)は、関数の仮引数と見なされます。
仮引数の型は、コンパイラによって文脈から推論されます。

ラムダ式は、関数を他の関数の引数として渡す時に便利です。
ラムダ式によって、わざわざ関数アイテムを定義する必要はありません。

重要な事として、ラムダ式はその環境を _キャプチャ(capture)_ します。
これは、通常の[関数定義][functions]では出来ません。
キャプチャの型は、ラムダ式の[関数型][function-types]に依存します。
最も簡単なラムダ式は、参照キャプチャしラムダ式内で言及された外側の変数に対するポインタを借り(borrow)ます。
また、コンパイラはコピーキャプチャするかムーブキャプチャするかを推定する。

この例では、`ten_times`という関数を定義し、この関数は、高階関数を引数に取ります。

```
fn ten_times<F>(f: F) where F: Fn(i32) {
    for index in 0..10 {
        f(index);
    }
}

ten_times(|j| println!("hello, {}", j));
```

[functions]: functions.html
[function-types]: function-types.html
