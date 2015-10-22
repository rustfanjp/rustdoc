% Expressions

## Expressions

An expression may have two roles: it always produces a *value*, and it may have
*effects* (otherwise known as "side effects"). An expression *evaluates to* a
value, and has effects during *evaluation*. Many expressions contain
sub-expressions (operands). The meaning of each kind of expression dictates
several things:

* Whether or not to evaluate the sub-expressions when evaluating the expression
* The order in which to evaluate the sub-expressions
* How to combine the sub-expressions' values to obtain the value of the expression

In this way, the structure of expressions dictates the structure of execution.
Blocks are just another kind of expression, so blocks, statements, expressions,
and blocks again can recursively nest inside each other to an arbitrary depth.

