* [Notation](notation.md)
    * [Unicode productions](unicode-productions.md)
    * [String table productions](string-table-productions.md)
* [Lexical structure](lexical-structure.md)
    * [Input format](input-format.md)
    * [Identifiers](identifiers.md)
    * [Comments](comments.md)
    * [Whitespace](whitespace.md)
    * [Tokens](tokens.md)
        * [Literals](literals.md)
            * [Examples](examples.md)
                * [Characters and strings](characters-and-strings.md)
                * [Byte escapes](byte-escapes.md)
                * [Unicode escapes](unicode-escapes.md)
                * [Numbers](numbers.md)
                * [Suffixes](suffixes.md)
            * [Character and string literals](character-and-string-literals.md)
                * [Character literals](character-literals.md)
                * [String literals](string-literals.md)
                * [Character escapes](character-escapes.md)
                * [Raw string literals](raw-string-literals.md)
            * [Byte and byte string literals](byte-and-byte-string-literals.md)
                * [Byte literals](byte-literals.md)
                * [Byte string literals](byte-string-literals.md)
                * [Raw byte string literals](raw-byte-string-literals.md)
            * [Number literals](number-literals.md)
                * [Integer literals](integer-literals.md)
                * [Floating-point literals](floating-point-literals.md)
            * [Boolean literals](boolean-literals.md)
        * [Symbols](symbols.md)
    * [Paths](paths.md)
* [Syntax extensions](syntax-extensions.md)
    * [Macros](macros.md)
        * [Macro By Example](macro-by-example.md)
        * [Parsing limitations](parsing-limitations.md)
* [Crates and source files](crates-and-source-files.md)
* [Items and attributes](items-and-attributes.md)
    * [Items](items.md)
        * [Type Parameters](type-parameters.md)
        * [Modules](modules.md)
            * [Extern crate declarations](extern-crate-declarations.md)
            * [Use declarations](use-declarations.md)
        * [Functions](functions.md)
            * [Generic functions](generic-functions.md)
            * [Unsafety](unsafety.md)
                * [Unsafe functions](unsafe-functions.md)
                * [Unsafe blocks](unsafe-blocks.md)
                * [Behavior considered undefined](behavior-considered-undefined.md)
                * [Behavior not considered unsafe](behavior-not-considered-unsafe.md)
            * [Diverging functions](diverging-functions.md)
            * [Extern functions](extern-functions.md)
        * [Type aliases](type-aliases.md)
        * [Structures](structures.md)
        * [Enumerations](enumerations.md)
        * [Constant items](constant-items.md)
        * [Static items](static-items.md)
            * [Mutable statics](mutable-statics.md)
        * [Traits](traits.md)
        * [Implementations](implementations.md)
        * [External blocks](external-blocks.md)
    * [Visibility and Privacy](visibility-and-privacy.md)
        * [Re-exporting and Visibility](re-exporting-and-visibility.md)
    * [Attributes](attributes.md)
        * [Crate-only attributes](crate-only-attributes.md)
        * [Module-only attributes](module-only-attributes.md)
        * [Function-only attributes](function-only-attributes.md)
        * [Static-only attributes](static-only-attributes.md)
        * [FFI attributes](ffi-attributes.md)
        * [Macro-related attributes](macro-related-attributes.md)
        * [Miscellaneous attributes](miscellaneous-attributes.md)
        * [Conditional compilation](conditional-compilation.md)
        * [Lint check attributes](lint-check-attributes.md)
        * [Language items](language-items.md)
        * [Inline attributes](inline-attributes.md)
        * [`derive`](derive.md)
        * [Compiler Features](compiler-features.md)
* [Statements and expressions](statements-and-expressions.md)
    * [Statements](statements.md)
        * [Declaration statements](declaration-statements.md)
            * [Item declarations](item-declarations.md)
            * [Variable declarations](variable-declarations.md)
        * [Expression statements](expression-statements.md)
    * [Expressions](expressions.md)
        * [Lvalues, rvalues and temporaries](lvalues-rvalues-and-temporaries.md)
        * [Temporary lifetimes](temporary-lifetimes.md)
        * [Moved and copied types](moved-and-copied-types.md)
        * [Literal expressions](literal-expressions.md)
        * [Path expressions](path-expressions.md)
        * [Tuple expressions](tuple-expressions.md)
        * [Structure expressions](structure-expressions.md)
        * [Block expressions](block-expressions.md)
        * [Method-call expressions](method-call-expressions.md)
        * [Field expressions](field-expressions.md)
        * [Array expressions](array-expressions.md)
        * [Index expressions](index-expressions.md)
        * [Range expressions](range-expressions.md)
        * [Unary operator expressions](unary-operator-expressions.md)
        * [Binary operator expressions](binary-operator-expressions.md)
            * [Arithmetic operators](arithmetic-operators.md)
            * [Bitwise operators](bitwise-operators.md)
            * [Lazy boolean operators](lazy-boolean-operators.md)
            * [Comparison operators](comparison-operators.md)
            * [Type cast expressions](type-cast-expressions.md)
            * [Assignment expressions](assignment-expressions.md)
            * [Compound assignment expressions](compound-assignment-expressions.md)
            * [Operator precedence](operator-precedence.md)
        * [Grouped expressions](grouped-expressions.md)
        * [Call expressions](call-expressions.md)
        * [Lambda expressions](lambda-expressions.md)
        * [Infinite loops](infinite-loops.md)
        * [Break expressions](break-expressions.md)
        * [Continue expressions](continue-expressions.md)
        * [While loops](while-loops.md)
        * [For expressions](for-expressions.md)
        * [If expressions](if-expressions.md)
        * [Match expressions](match-expressions.md)
        * [If let expressions](if-let-expressions.md)
        * [While let loops](while-let-loops.md)
        * [Return expressions](return-expressions.md)
* [Type system](type-system.md)
    * [Types](types.md)
        * [Primitive types](primitive-types.md)
            * [Machine types](machine-types.md)
            * [Machine-dependent integer types](machine-dependent-integer-types.md)
        * [Textual types](textual-types.md)
        * [Tuple types](tuple-types.md)
        * [Array, and Slice types](array-and-slice-types.md)
        * [Structure types](structure-types.md)
        * [Enumerated types](enumerated-types.md)
        * [Recursive types](recursive-types.md)
        * [Pointer types](pointer-types.md)
        * [Function types](function-types.md)
            * [Function types for specific items](function-types-for-specific-items.md)
        * [Closure types](closure-types.md)
        * [Trait objects](trait-objects.md)
        * [Type parameters](type-parameters.md)
        * [Self types](self-types.md)
    * [Subtyping](subtyping.md)
    * [Type coercions](type-coercions.md)
        * [Coercion sites](coercion-sites.md)
        * [Coercion types](coercion-types.md)
* [Special traits](special-traits.md)
    * [The `Copy` trait](the-copy-trait.md)
    * [The `Sized` trait](the-sized-trait.md)
    * [The `Drop` trait](the-drop-trait.md)
    * [The `Deref` trait](the-deref-trait.md)
* [Memory model](memory-model.md)
    * [Memory allocation and lifetime](memory-allocation-and-lifetime.md)
    * [Memory ownership](memory-ownership.md)
    * [Variables](variables.md)
* [Linkage](linkage.md)
* [Appendix: Rationales and design trade-offs](appendix-rationales-and-design-trade-offs.md)
* [Appendix: Influences](appendix-influences.md)