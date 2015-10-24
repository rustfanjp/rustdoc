% Behavior considered undefined

##### Behavior considered undefined

これは、`unsafe`ブロック(block)や`unsafe`関数(function)も含めて、全てのRustコードで禁止されている動作のリストです。
型チェックによって、安全なコードでは、これらの動作を起こさない事が保証されています。

* データ競合。
* null生ポインタ、ダングリング生ポインタのデリファレンス。
* [undef][undefined-values](未初期化)メモリの読み出し。
* [ポインタエイリアシング規則][pointer-aliasing-rules]違反。
* `&mut`と`&`の、noaliasルール違反。ただし、`&T`が`UnsafeCell<U>`を含んでいた場合は、良い。
* mutableでないデータを変更する事。ただし、`UnsafeCell<UL`を含んでいた場合は、良い。
* コンパイラ組み込み機能による未定義動作呼び出し。
  * `std::ptr::offset`(`offset`組み込み)によって、オブジェクトの領域の外側の指定する。ただし、1バイト外側は許される。
  * `std::ptr::copy_nonoverlapping_memory`(`memcpy32`/`memcpy64`組み込み)をオーバーラップした領域に対して呼び出す。
* プリミティブ(primitive)型に対する不正な値。
  * 参照(reference)かボックス(box)に対するダングリング/ヌル値の設定。
  * `bool`にたいして`false`(0)と`true`(1)以外の値の設定。
  * `enum`型に対する定義されていない値の設定。
  * `char`型に対する、サロゲートや`char::MAX`を超える値の設定。
  * `str`型に対する、非UTF8バイト列の設定。
* Rustプログラムと外部プログラムの間のアンワインド(unwind)。特に、Rustのエラー処理システムは他の言語での例外ハンドリング機構と互換性が無い。unwindはFFI境界を通して管理される。

(訳注) noaliasルールとは、引数に渡されたポインタの指している領域に、引数に渡されていない静的変数などを通してアクセスする事。

[undefined-values]: http://llvm.org/docs/LangRef.html#undefined-values
[pointer-aliasing-rules]: http://llvm.org/docs/LangRef.html#pointer-aliasing-rules
[noalias]: http://llvm.org/docs/LangRef.html#noalias
