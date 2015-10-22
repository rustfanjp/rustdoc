% Coercion types

### Coercion types

Coercion is allowed between the following types:

* `T` to `U` if `T` is a subtype of `U` (*reflexive case*)

* `T_1` to `T_3` where `T_1` coerces to `T_2` and `T_2` coerces to `T_3`
(*transitive case*)

    Note that this is not fully supported yet

* `&mut T` to `&T`

* `*mut T` to `*const T`

* `&T` to `*const T`

* `&mut T` to `*mut T`

* `&T` to `&U` if `T` implements `Deref<Target = U>`. For example:

  ```rust
  use std::ops::Deref;

  struct CharContainer {
      value: char
  }

  impl Deref for CharContainer {
      type Target = char;

      fn deref<'a>(&'a self) -> &'a char {
          &self.value
      }
  }

  fn foo(arg: &char) {}

  fn main() {
      let x = &mut CharContainer { value: 'y' };
      foo(x); //&mut CharContainer is coerced to &char.
  }
  ```

* `&mut T` to `&mut U` if `T` implements `DerefMut<Target = U>`.

* TyCtor(`T`) to TyCtor(coerce_inner(`T`)), where TyCtor(`T`) is one of
    - `&T`
    - `&mut T`
    - `*const T`
    - `*mut T`
    - `Box<T>`

    and where
    - coerce_inner(`[T, ..n]`) = `[T]`
    - coerce_inner(`T`) = `U` where `T` is a concrete type which implements the
    trait `U`.

    In the future, coerce_inner will be recursively extended to tuples and
    structs. In addition, coercions from sub-traits to super-traits will be
    added. See [RFC401] for more details.

