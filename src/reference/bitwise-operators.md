% Bitwise operators

#### Bitwise operators

Like the [arithmetic operators](#arithmetic-operators), bitwise operators are
syntactic sugar for calls to methods of built-in traits. This means that
bitwise operators can be overridden for user-defined types. The default
meaning of the operators on standard types is given here. Bitwise `&`, `|` and
`^` applied to boolean arguments are equivalent to logical `&&`, `||` and `!=`
evaluated in non-lazy fashion.

* `&`
  : Bitwise AND.
    Calls the `bitand` method of the `std::ops::BitAnd` trait.
* `|`
  : Bitwise inclusive OR.
    Calls the `bitor` method of the `std::ops::BitOr` trait.
* `^`
  : Bitwise exclusive OR.
    Calls the `bitxor` method of the `std::ops::BitXor` trait.
* `<<`
  : Left shift.
    Calls the `shl` method of the `std::ops::Shl` trait.
* `>>`
  : Right shift (arithmetic).
    Calls the `shr` method of the `std::ops::Shr` trait.

