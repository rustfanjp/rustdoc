% Unary operator expressions

### Unary operator expressions

Rust defines the following unary operators. They are all written as prefix operators,
before the expression they apply to.

* `-`
  : Negation. May only be applied to numeric types.
* `*`
  : Dereference. When applied to a [pointer](#pointer-types) it denotes the
    pointed-to location. For pointers to mutable locations, the resulting
    [lvalue](#lvalues,-rvalues-and-temporaries) can be assigned to.
    On non-pointer types, it calls the `deref` method of the `std::ops::Deref`
    trait, or the `deref_mut` method of the `std::ops::DerefMut` trait (if
    implemented by the type and required for an outer expression that will or
    could mutate the dereference), and produces the result of dereferencing the
    `&` or `&mut` borrowed pointer returned from the overload method.
* `!`
  : Logical negation. On the boolean type, this flips between `true` and
    `false`. On integer types, this inverts the individual bits in the
    two's complement representation of the value.
* `&` and `&mut`
  : Borrowing. When applied to an lvalue, these operators produce a
    reference (pointer) to the lvalue. The lvalue is also placed into
    a borrowed state for the duration of the reference. For a shared
    borrow (`&`), this implies that the lvalue may not be mutated, but
    it may be read or shared again. For a mutable borrow (`&mut`), the
    lvalue may not be accessed in any way until the borrow expires.
    If the `&` or `&mut` operators are applied to an rvalue, a
    temporary value is created; the lifetime of this temporary value
    is defined by [syntactic rules](#temporary-lifetimes).

