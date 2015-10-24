% Extern functions

#### Extern functions

extern関数(extern function)は、Rustの外部関数インターフェース(Foregin Function Interface, FFI)の一部です。
externalブロックは、外部のコードを呼び*出す*事を許しますが、extern関数は、外部のコードから呼び*出される*事を許します。
`extern`キーワードによる修飾子がある以外、その他の意味論は普通の関数と同様です。

(訳注) C/C++で言う外部リンケージを指定します。

```
// Declares an extern fn, the ABI defaults to "C"
extern fn new_i32() -> i32 { 0 }

// Declares an extern fn with "stdcall" ABI
extern "stdcall" fn new_i32_stdcall() -> i32 { 0 }
```

通常の関数とは異なり、extern関数は`extern "ABI" fn()`という形式を取ります。
[externブロック][external-blocks]で次の様に宣言しても同様です。

```
# extern fn new_i32() -> i32 { 0 }
let fptr: extern "C" fn() -> i32 = new_i32;
```

(訳注) この方法では、リンケージ指定と関数の本体を分離できるのが利点です。

extern関数は、Rustコード内からも直接呼ばれるかもしれません。

[external-blocks]: external-blocks.html
