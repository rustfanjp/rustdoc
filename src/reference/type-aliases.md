% Type aliases

### Type aliases

_型エイリアス(type alias)_ はすでに存在する[型(type)][types]の新しい名前を定義します。
型エイリアスは`type`キーワードと共に宣言されます。
全ての値は、特定の1つの型を持ちますが、異なるトレイト(trait)や、複数の異なった型制約(type constraint)と互換性があるかもしれません。

例えば、次の定義は、`Point`を`(u8, u8)`型、符号無8ビット整数のペアのシノニムとして定義しています。

```
type Point = (u8, u8);
let p: Point = (41, 68);
```
