% `derive`

### `derive`

The `derive` attribute allows certain traits to be automatically implemented
for data structures. For example, the following will create an `impl` for the
`PartialEq` and `Clone` traits for `Foo`, the type parameter `T` will be given
the `PartialEq` or `Clone` constraints for the appropriate `impl`:

```
#[derive(PartialEq, Clone)]
struct Foo<T> {
    a: i32,
    b: T
}
```

The generated `impl` for `PartialEq` is equivalent to

```
# struct Foo<T> { a: i32, b: T }
impl<T: PartialEq> PartialEq for Foo<T> {
    fn eq(&self, other: &Foo<T>) -> bool {
        self.a == other.a && self.b == other.b
    }

    fn ne(&self, other: &Foo<T>) -> bool {
        self.a != other.a || self.b != other.b
    }
}
```

