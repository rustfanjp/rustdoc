% Mutable statics

#### Mutable statics

もし、静的アイテム(static item)が`mut`キーワードと共に宣言された場合、その静的アイテムはミュータブル(mutable)であり、その静的アイテムに対する変更操作を行えます。
Rustの目標の1つに、平行性バグを起こしにくい事があります。
そして、静的アイテムに対する変更操作は、競合条件の原因となりやすいです。
このため、ミュータブル(mutable)な静的アイテムに対する読み書きは、`unsafe`ブロック(block)の中で行う必要が有ります。
ユーザーは、同じプロセスの他のスレッドに対して、ミュータブル静的アイテムに対する変更操作が安全である事を保証する必要が有ります。

ミュータブル静的アイテムは非常に便利で、`extern`ブロックの中で、Cライブラリと共に使ったり、Cライブラリから持ってきたりする事ができます。

```
# fn atomic_add(_: &mut u32, _: u32) -> u32 { 2 }

static mut LEVELS: u32 = 0;

// This violates the idea of no shared state, and this doesn't internally
// protect against races, so this function is `unsafe`
unsafe fn bump_levels_unsafe1() -> u32 {
    let ret = LEVELS;
    LEVELS += 1;
    return ret;
}

// Assuming that we have an atomic_add function which returns the old value,
// this function is "safe" but the meaning of the return value may not be what
// callers expect, so it's still marked as `unsafe`
unsafe fn bump_levels_unsafe2() -> u32 {
    return atomic_add(&mut LEVELS, 1);
}
```

ミュータブル静的アイテムは、`Sync`で無くてよいという意外は通常の静的アイテムと同じ制限を持ちます。
