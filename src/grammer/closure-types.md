% Closure types

### Closure types

```antlr
closure_type := [ 'unsafe' ] [ '<' lifetime-list '>' ] '|' arg-list '|'
                [ ':' bound-list ] [ '->' type ]
procedure_type := 'proc' [ '<' lifetime-list '>' ] '(' arg-list ')'
                  [ ':' bound-list ] [ '->' type ]
lifetime-list := lifetime | lifetime ',' lifetime-list
arg-list := ident ':' type | ident ':' type ',' arg-list
bound-list := bound | bound '+' bound-list
bound := path | lifetime
```

