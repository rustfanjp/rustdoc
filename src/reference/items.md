% Items

## Items

_アイテム(item)_ﾊ､クレート(crate)の要素です。
アイテムは、ネストした[モジュール(module)][modules]によってクレート内に管理されています。
全てのクレートは、"一番外側"の唯一の無名モジュールを持ちます。
全てのアイテムは、クレートのモジュール木の中の[標準パス][paths]を持ちます。

[modules]: modules.html
[paths]: paths.html

アイテムはコンパイル時に決定され、実行中は不変です。
通常はリードオンリメモリに配置されます。

いくつかの種類のアイテムが有ります。

* [`extern crate`宣言](extern-crate-declarations.html)
* [`use`宣言](use-declarations.html)
* [モジュール(module)](modules.html)
* [関数(function)](functions.html)
* [型定義(type definition)](grammar.htmltype-definitions.html)
* [構造体(structure)](structures.html)
* [列挙型(enumeration)](enumerations.html)
* [定数アイテム(constant item)](constant-items.html)
* [静的アイテム(static item)](static-items.html)
* [トレイト(trait)](traits.html)
* [実装(implement)](implementations.html)

いくつかのアイテムは、サブアイテムを宣言するための暗黙のスコープを作ります。
つまり、関数やモジュールの中に、アイテムの宣言と文(statement)、ブロック(block)等を混ぜる事が出来ます。
これらのアイテムの意味は、そのスコープの外で宣言された時と同じです。
つまり、静的で、*標準パス*は、モジュール木によってのみ決定されます。
いくつかのアイテムは、定義可能な場所が文法によって制限されているかもしれません。
