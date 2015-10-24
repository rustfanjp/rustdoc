% Functions

### Functions

_関数アイテム(function item)_ は、名前を持ち、[文(statement)][statements]の列と、省略可能な[式(expression)][expressions]と、仮引数の集合を持ちます。
関数は、`fn`キーワードと共に始まります。
関数は、*入力(input)* [*変数(variable)*][variables]を仮引数として宣言します。
関数呼び出しの際には、実引数を関数に渡します。
関数は、*出力*(output)* [*型(type)*][types]を返値として宣言します。

関数は、第一級*値(value)*としてコピーされるかもしれません。
この値は、対応する[*関数型(function type)*][function-types]を持ちます。
関数型は、関数アイテムと同様に呼び出せますが、関数呼び出しについて呼ぶなコストが有ります。

[statements]: statements.html
[expressions]: expressions.html
[variables]: variables.html
[types]: types.html
[function-types]: function-types.html

(訳注) 関数オブジェクトは通常、書き換え可能な関数ポインタとして実装されます。
関数ポインタのデリファレンスは通常、インライン化できないので、ポインタを辿るコストがかかります。

関数の全てのコントロールパスは、`return`式か、分岐(diverge)式で終わります。
もし関数の一番外側のブロックが、final-expressionの位置に値を生成する式を持っていた場合、その式が暗黙の`return`式だと見なされます。

これが関数の例です。

```rust
fn add(x: i32, y: i32) -> i32 {
    return x + y;
}
```

`let`束縛と同じように、関数の仮引数は不可反駁(ireefutable)パターンです。
`let`で有効なパターンは関数の仮引数でも有効です。

(訳注) 不可反駁パターンとは、必ずマッチが成功するパターンです。

```rust
fn first((value, _): (i32, i32)) -> i32 { value }
```
