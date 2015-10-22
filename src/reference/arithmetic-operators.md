% Arithmetic operators

#### Arithmetic operators

Binary arithmetic expressions are syntactic sugar for calls to built-in traits,
defined in the `std::ops` module of the `std` library. This means that
arithmetic operators can be overridden for user-defined types. The default
meaning of the operators on standard types is given here.

* `+`
  : Addition and array/string concatenation.
    Calls the `add` method on the `std::ops::Add` trait.
* `-`
  : Subtraction.
    Calls the `sub` method on the `std::ops::Sub` trait.
* `*`
  : Multiplication.
    Calls the `mul` method on the `std::ops::Mul` trait.
* `/`
  : Quotient.
    Calls the `div` method on the `std::ops::Div` trait.
* `%`
  : Remainder.
    Calls the `rem` method on the `std::ops::Rem` trait.

