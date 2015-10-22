% Operator precedence

#### Operator precedence

The precedence of Rust binary operators is ordered as follows, going from
strong to weak:

```{.text .precedence}
as
* / %
+ -
<< >>
&
^
|
== != < > <= >=
&&
||
= ..
```

Operators at the same precedence level are evaluated left-to-right. [Unary
operators](#unary-operator-expressions) have the same precedence level and are
stronger than any of the binary operators.

