% Hello, Cargo!

[Cargo][cratesio]は、RustaceansがRustプロジェクトを管理するために使うツールです。
Cargoは今の所、バージョン1.0未満で、まだまだ開発中の状態です。
しかしながら、多くのRustプロジェクトを管理するためには、すでにほぼ十分ですので、Rustプロジェクトは最初からCargoを使う事を想定されています。

[cratesio]: http://doc.crates.io

Cargoは3つの事を行います。
コードのビルド、依存パッケージのダウンロード、依存パッケージのビルドです。
まずは、依存性を持たないプログラムを扱い、後から依存性を追加します。
Cargoでは、後から依存性を追加するのも非常に容易です。

もし、Rustを公式のインストーラから導入した場合、Cargoも導入されています。
他の方法でRustを導入した場合、[Cargo README][cargoreadme]を確認して下さい。

[cargoreadme]: https://github.com/rust-lang/cargo#installing-cargo-from-nightlies

## Cargoへの変換


