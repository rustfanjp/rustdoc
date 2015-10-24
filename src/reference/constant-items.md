% Constant items

### Constant items

*定数アイテム(constant item)* は、名前を持った _定数値(constant value)_ です。
定数値は、プログラムの実行時には特定のメモリに格納されているとは限らず、実行コードに直接埋め込まれているかもしれません。
つまり、もし可能ならインライン化されています。
同じ定数アイテムに対する参照(reference)は、同じメモリアドレスを指しているとは限りません。

定数値は、デストラクタ(destructor)を持ってはいけません。
これを守っていれば、ほとんどのデータ形式が定数値になりえます。
他の定数値のアドレスを示す定数値という物も考えられますが、その様な定数値は、`static`寿命(lifetime)を持ちます。
しかしながら、コンパイラは定数値を様々な場所に何度も移動するかもしれず、アドレスは安定ではありません。

定数値は、明示的に型(type)指定される必要があります。
型には、`bool`、`char`、数や、それらプリミティブ(primitive)型の派生型が有り得ます。
派生型には、`static`寿命を持つ参照、固定サイズ配列、タプル(tuple)、列挙バリアント(enum variant)、構造体(struct)が有り得ます。

```
const BIT1: u32 = 1 << 0;
const BIT2: u32 = 1 << 1;

const BITS: [u32; 2] = [BIT1, BIT2];
const STRING: &'static str = "bitstring";

struct BitsNStrings<'a> {
    mybits: [u32; 2],
    mystring: &'a str
}

const BITS_N_STRINGS: BitsNStrings<'static> = BitsNStrings {
    mybits: BITS,
    mystring: STRING
};
```
