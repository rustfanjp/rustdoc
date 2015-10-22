% Items

## Items

An _item_ is a component of a crate. Items are organized within a crate by a
nested set of [modules](#modules). Every crate has a single "outermost"
anonymous module; all further items within the crate have [paths](#paths)
within the module tree of the crate.

Items are entirely determined at compile-time, generally remain fixed during
execution, and may reside in read-only memory.

There are several kinds of item:

* [`extern crate` declarations](#extern-crate-declarations)
* [`use` declarations](#use-declarations)
* [modules](#modules)
* [functions](#functions)
* [type definitions](grammar.html#type-definitions)
* [structures](#structures)
* [enumerations](#enumerations)
* [constant items](#constant-items)
* [static items](#static-items)
* [traits](#traits)
* [implementations](#implementations)

Some items form an implicit scope for the declaration of sub-items. In other
words, within a function or module, declarations of items can (in many cases)
be mixed with the statements, control blocks, and similar artifacts that
otherwise compose the item body. The meaning of these scoped items is the same
as if the item was declared outside the scope &mdash; it is still a static item
&mdash; except that the item's *path name* within the module namespace is
qualified by the name of the enclosing item, or is private to the enclosing
item (in the case of functions). The grammar specifies the exact locations in
which sub-item declarations may appear.

