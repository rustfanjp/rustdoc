% Moved and copied types

#### Moved and copied types

When a [local variable](#variables) is used as an
[rvalue](#lvalues,-rvalues-and-temporaries), the variable will be copied
if its type implements `Copy`. All others are moved.

