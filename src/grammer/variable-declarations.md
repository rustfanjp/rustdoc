% Variable declarations

#### Variable declarations

```antlr
let_decl : "let" pat [':' type ] ? [ init ] ? ';' ;
init : [ '=' ] expr ;
```

