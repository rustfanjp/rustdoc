% Comparison operators

#### Comparison operators

Comparison operators are, like the [arithmetic
operators](#arithmetic-operators), and [bitwise operators](#bitwise-operators),
syntactic sugar for calls to built-in traits. This means that comparison
operators can be overridden for user-defined types. The default meaning of the
operators on standard types is given here.

* `==`
  : Equal to.
    Calls the `eq` method on the `std::cmp::PartialEq` trait.
* `!=`
  : Unequal to.
    Calls the `ne` method on the `std::cmp::PartialEq` trait.
* `<`
  : Less than.
    Calls the `lt` method on the `std::cmp::PartialOrd` trait.
* `>`
  : Greater than.
    Calls the `gt` method on the `std::cmp::PartialOrd` trait.
* `<=`
  : Less than or equal.
    Calls the `le` method on the `std::cmp::PartialOrd` trait.
* `>=`
  : Greater than or equal.
    Calls the `ge` method on the `std::cmp::PartialOrd` trait.

