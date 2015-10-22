% Item declarations

#### Item declarations

An _item declaration statement_ has a syntactic form identical to an
[item](#items) declaration within a module. Declaring an item &mdash; a
function, enumeration, structure, type, static, trait, implementation or module
&mdash; locally within a statement block is simply a way of restricting its
scope to a narrow region containing all of its uses; it is otherwise identical
in meaning to declaring the item outside the statement block.

> **Note**: there is no implicit capture of the function's dynamic environment when
> declaring a function-local item.

