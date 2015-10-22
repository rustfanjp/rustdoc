% Trait objects

### Trait objects

In Rust, a type like `&SomeTrait` or `Box<SomeTrait>` is called a _trait object_.
Each instance of a trait object includes:

 - a pointer to an instance of a type `T` that implements `SomeTrait`
 - a _virtual method table_, often just called a _vtable_, which contains, for
   each method of `SomeTrait` that `T` implements, a pointer to `T`'s
   implementation (i.e. a function pointer).

The purpose of trait objects is to permit "late binding" of methods. A call to
a method on a trait object is only resolved to a vtable entry at compile time.
The actual implementation for each vtable entry can vary on an object-by-object
basis.

Note that for a trait object to be instantiated, the trait must be
_object-safe_. Object safety rules are defined in [RFC 255].

[RFC 255]: https://github.com/rust-lang/rfcs/blob/master/text/0255-object-safety.md

Given a pointer-typed expression `E` of type `&T` or `Box<T>`, where `T`
implements trait `R`, casting `E` to the corresponding pointer type `&R` or
`Box<R>` results in a value of the _trait object_ `R`. This result is
represented as a pair of pointers: the vtable pointer for the `T`
implementation of `R`, and the pointer value of `E`.

An example of a trait object:

```
trait Printable {
  fn stringify(&self) -> String;
}

impl Printable for i32 {
  fn stringify(&self) -> String { self.to_string() }
}

fn print(a: Box<Printable>) {
   println!("{}", a.stringify());
}

fn main() {
   print(Box::new(10) as Box<Printable>);
}
```

In this example, the trait `Printable` occurs as a trait object in both the
type signature of `print`, and the cast expression in `main`.

