% String table productions

## String table productions

Rust文法のいくつかの規則は、非常に簡単です。
特に[単項演算子(unary operator)][unary-operator-expressions]、[二項演算子(binary operator)][binary-operator-expressions]、[キーワード(keyword)][keywords]は、単に引用符無しの、空白で分けられた、印字可能文字列の表です。
これらは、[トークン(token)][tokens]の生成規則のためのサブ規則となっています。
通常、ソースコードは、決定性有限オートマトンによるパーサーによる字句解析フェイズにおいてトークン列に分解されます。

[unary-operator-expressions]: unary-operator-expressions.html
[binary-operator-expressions]: binary-operator-expressions.html
[keywords]: grammar.html#keywords
[tokens]: tokens.html

/* TODO: grammer */

文法規則中で、二重引用符(`"`)で囲まれた文字列を見た場合、それは上で述べた単純な文法を持った生成規則を指し示します。
詳細は、[トークン][tokens]を参照して下さい。

[tokens]: tokens.html
