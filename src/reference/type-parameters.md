% Type parameters

### Type parameters

アイテム(item)の本体が、型仮引数宣言(type parameter declaration)を持つとき、その型仮引数の名前は、型を指し示します。

```ignore
fn to_vec<A: Clone>(xs: &[A]) -> Vec<A> {
    if xs.is_empty() {
       return vec![];
    }
    let first: A = xs[0].clone();
    let mut rest: Vec<A> = to_vec(&xs[1..]);
    rest.insert(0, first);
    rest
}
```

ここで、`first`は型`A`を持ち、`A`は`to_vec`の`A`型仮引数を示します。
`rest`は、`Vec<A>`型を持ち、このベクタの要素型は`A`です。
