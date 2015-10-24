% Macros

## Macros
`macro_rules`によって、文法拡張を宣言的なやり方で定義出来ます。
この様な拡張を"macros by example"や、単に"マクロ(macro)"と呼び、[コンパイラプラグイン(compiler plugin)][plugins]における"字句マクロ"と区別します。

現在の所、マクロは、式(expression)、文(statement)、アイテム(item)、パターン(pattern)に展開出来ます。

(`sep_token`は`*`と`+`以外の任意のトークンで、`non_special_token`はデリミタ(delimiter)と、`$`以外の任意のトークンです。)

マクロ展開器は、マクロ呼び出しを見つけると、マクロ規則の適応を試みます。
マクロ展開器は、最初に成功したマッチを翻訳(transcribe)します。
マッチングと翻訳は非常に関連性が有るので、後ほど、一緒に説明します。

(訳注) 原文においても、このページは著しく情報が不足しています。
詳細は、Rust bookの[マクロ][macros]を参照するのが良いでしょう。

[plugins]: plugins.html
[macros]: ../book/macros.html
