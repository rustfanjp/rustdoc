% Structures

### Structures

_構造体(structure)_ とは、`struct`キーワードと共に定義される[構造体型(structure type)][structure-types]です。
これが構造体の例です。

```
struct Point {x: i32, y: i32}
let p = Point {x: 10, y: 11};
let px: i32 = p.x;
```

_タプル構造体(tuple structure)_ とは、`struct`キーワードと共に定義される[タプル型(tuple type)][tuple-types]です。
これがタプル構造体の例です。

```
struct Point(i32, i32);
let p = Point(10, 11);
let px: i32 = match p { Point(x, _) => x };
```

_単体構造体(unit-like structure)_とは、いかなるフィールドも持たない構造体です。
単体構造体は通常、単一の値しか持ちません。
これが単体構造体の例です。

```
struct Cookie;
let c = [Cookie, Cookie, Cookie, Cookie];
```

構造体のメモリレイアウトはデフォルトでは指定されません。
指定するには、[`repr`アトリビュート(attribute)][ffi-attributes]を用いてください。

[structure-types]: structure-types.html
[tuple-types]: tuple-types.html
[ffi-attributes]: ffi-attributes.html
