% Unsafety

#### Unsafety

安全でない(unsafe)な操作とは、Rustの意味論で保証されているメモリ安全性(memory-safety)を破り得る操作の事です。

次の様な操作は、安全性を保証されている範囲では使えません。

- [生ポインタ(raw pointer)][pointer-types]のデリファレンス。
- [ミュータブル静的変数(mutable static variable)][mutable-statics]に対する読み書き。
- 安全でない関数(intrinsicsや外部関数)の呼び出し。

[pointer-types]: pointer-types.html
[mutable-statics]: mutable-statics.html
