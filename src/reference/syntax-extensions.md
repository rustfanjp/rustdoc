% Syntax extensions

# Syntax extensions

Rustのいくつかのちょっとした機能は、それ専用の文法を与える程ではありませんが、関数として実装するのも難しい物もあります。
そういった機能は、`some_extension!(...)`という相応の文法を利用して実装されています。

`rustc`では、2つの方法によって文法を拡張する事が出来ます。

* [コンパイラプラグイン(compiler plugin)][plugins] は、コンパイル時に構文木を操作する任意のRustコードを含める事が出来ます。
  コンパイラプラグインのためのインターフェースはstableではありません。

* [マクロ(macro)][macros]は、高レベルの宣言型の文法を定義します。


/* TODO:  */
[plugins]: plugins.html
[macros]: macros.html
