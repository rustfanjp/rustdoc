% Lvalues, rvalues and temporaries

#### Lvalues, rvalues and temporaries

Expressions are divided into two main categories: _lvalues_ and _rvalues_.
Likewise within each expression, sub-expressions may occur in _lvalue context_
or _rvalue context_. The evaluation of an expression depends both on its own
category and the context it occurs within.

An lvalue is an expression that represents a memory location. These expressions
are [paths](#path-expressions) (which refer to local variables, function and
method arguments, or static variables), dereferences (`*expr`), [indexing
expressions](#index-expressions) (`expr[expr]`), and [field
references](#field-expressions) (`expr.f`). All other expressions are rvalues.

The left operand of an [assignment](#assignment-expressions) or
[compound-assignment](#compound-assignment-expressions) expression is
an lvalue context, as is the single operand of a unary
[borrow](#unary-operator-expressions). The discriminant or subject of
a [match expression](#match-expressions) may be an lvalue context, if
ref bindings are made, but is otherwise an rvalue context. All other
expression contexts are rvalue contexts.

When an lvalue is evaluated in an _lvalue context_, it denotes a memory
location; when evaluated in an _rvalue context_, it denotes the value held _in_
that memory location.

