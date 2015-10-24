% If let expressions

### If let expressions

```antlr
if_let_expr : "if" "let" pat '=' expr '{' block '}'
               else_tail ? ;
else_tail : "else" [ if_expr | if_let_expr | '{' block '}' ] ;
```

