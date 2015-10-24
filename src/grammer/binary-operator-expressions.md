% Binary operator expressions

### Binary operator expressions

```antlr
binop_expr : expr binop expr | type_cast_expr
           | assignment_expr | compound_assignment_expr ;
binop : arith_op | bitwise_op | lazy_bool_op | comp_op
```

