% Extern crate declarations

#### Extern crate declarations

`extern crate`宣言は、外部クレート(crate)への依存性を指定します。
外部クレートのスコープは、`extern_crate_decl`に与えられた`ident`に束縛されます。

外部クレートは、コンパイル時に`soname`を解決されます。
そして、その`soname`に対する実行時のリンケージ要求がリンカーに渡されます。
`soname`はコンパイル時に解決されますが、そのためにコンパイラのライブラリパスが走査され、`crateid`アトリビュートにマッチする物が選ばれます。
もし`crateid`が与えられなかった場合、`name`アトリビュートを元にマッチングされます。
`name`アトリビュートは、`extern_crate_decl`に与えられる`ident`です。

これが3つの`extern crate`宣言です。


```{rust.ignore}
extern crate pcre;

extern crate std; // equivalent to: extern crate std as std;

extern crate std as ruststd; // linking to 'std' under another name
```
