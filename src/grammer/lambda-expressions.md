% Lambda expressions

### Lambda expressions

```antlr
ident_list : [ ident [ ',' ident ]* ] ? ;
lambda_expr : '|' ident_list '|' expr ;
```

