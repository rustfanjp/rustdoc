% Installing Rust

Rustを使う最初の一歩は、Rustをインストールする事です。
Rustをインストールする方法をいくつかありますが、最も簡単なのは`rustup`スクリプトを用いる事です。
もし、LinuxかMacを使っているなら、ただ次のコマンドを実行するだけです。

> ノート: 行頭の`$`、`#`をタイプする必要はありません。`#`は管理者権限が必要な事を表します。

```bash
$curl -sf -L https://static.rust-lang.org/rustup.sh | sh
```

もし、`curl | sh`の[潜在的な危険性][insecurity]を懸念する、2ステップのインストール方法を使い、インストールスクリプトを思うままに検査して下さい。
また、後述する"disclaimer"を確認して下さい。

```bash
$ curl -f -L https://static.rust-lang.org/rustup.sh -0
$ sh rustup.sh
```

[insecurity]: http://curlpipesh.tumblr.com

もし、Windowsを使用していれば、[インストーラー][install-page]を使用してください。

> ノート: デフォルトではWindowsインストーラーはRustを%PATH%システム変数に追加しません。

[install-page]: https://www.rust-lang.org/install.html

## Uninstalling

悲しい事ですが、もしRustを使わないと決めたのならば、アンインストールスクリプトを実行してください。

```bash
$ sudo /usr/local/lib/rustlib/uninstall.sh
```

もし、Windowsインストーラーを使用したのなら、再度`.msi`を実行し、アンインストールオプションを選択して下さい。

## disclaimer

正当な指摘ですが、`curl | sh`するよう促す事を危険だと思う人もいます。
基本的にこのコマンドを実行すという事は、Rustの開発・メンテナンスを行っている人々がハッキング等を行わないと信じている事になります。
それは良い勘だと思いますがね！
もし、`curl | sh`を危険だと思うならば、[building Rust from Source][from-source]や[the official binary downloads][install-page]を確認して下さい。

[from-source]: https://github.com/rust-lang/rust#building-from-source

## プラットフォームサポート

Rustコンパイラーは多くのプラットフォーム上で走り、また多くのプラットフォーム向けのプログラムをコンパイルできます。
ただし、全てのプラットフォームで同等の機能がサポートされている分けではありません。
Rustのサポートレベルは3つの"Tier"に分けられ、それぞれ異なった保証があります。

プラットフォームは"target triple"と呼ばれる文字列によって識別されます。
下で現れる表の各列は、対応する機能がそれぞれのプラットフォームでサポートされているかを表します。

### Tier 1

Tier 1のプラットフォームは、"ビルド/動作保証"されています。
次の各要求を満たします。

* そのプラットフォーム向けの自動テストのセットアップとテスト実行
* `rust-lang/rust`のmasterブランチへの変更の、そのプラットフォーム向けの動作テスト成功
* 過去の公式リリースパッケージの提供
* そのプラットフォーム上でのビルド/使用方法の文書の整備

|  Target                       | std |rustc|cargo| notes                      |
|-------------------------------|-----|-----|-----|----------------------------|
| `x86_64-pc-windows-msvc`      |  ✓  |  ✓  |  ✓  | 64-bit MSVC (Windows 7+)   |
| `i686-pc-windows-gnu`         |  ✓  |  ✓  |  ✓  | 32-bit MinGW (Windows 7+)  |
| `x86_64-pc-windows-gnu`       |  ✓  |  ✓  |  ✓  | 64-bit MinGW (Windows 7+)  |
| `i686-apple-darwin`           |  ✓  |  ✓  |  ✓  | 32-bit OSX (10.7+, Lion+)  |
| `x86_64-apple-darwin`         |  ✓  |  ✓  |  ✓  | 64-bit OSX (10.7+, Lion+)  |
| `i686-unknown-linux-gnu`      |  ✓  |  ✓  |  ✓  | 32-bit Linux (2.6.18+)     |
| `x86_64-unknown-linux-gnu`    |  ✓  |  ✓  |  ✓  | 64-bit Linux (2.6.18+)     |

### Tier 2

Tier 2のプラットフォームは"ビルド保証"されています。
自動テストは行われないので、動作保証はされません。
しかしながら、大抵は良く動作しますし、パッチは常に歓迎です！
次の各要求を満たします。

* 自動ビルド環境がセットアップされている(ビルド保証)。ただし、実行テストは行われない。
* `rust-lang/rust`のmasterブランチへの変更の、そのプラットフォーム向けのビルドテスト成功
* 過去の公式リリースパッケージの提供

|  Target                       | std |rustc|cargo| notes                      |
|-------------------------------|-----|-----|-----|----------------------------|
| `i686-pc-windows-msvc`        |  ✓  |  ✓  |  ✓  | 32-bit MSVC (Windows 7+)   |

### Tier 3

Tier 3のプラットフォームは、サポートはされますが、ビルド・動作テストは行われません。
それぞれのプラットフォームにおける動作可能なビルドの信頼性は、それぞれのコミュニティの貢献に依存してムラがあります。
また、リリースパッケージやインストーラーは提供されません。
しかしながら、コミュニティによっては、非公式なパッケージを提供しているかもしれません。

|  Target                       | std |rustc|cargo| notes                      |
|-------------------------------|-----|-----|-----|----------------------------|
| `x86_64-unknown-linux-musl`   |  ✓  |     |     | 64-bit Linux with MUSL     |
| `arm-linux-androideabi`       |  ✓  |     |     | ARM Android                |
| `i686-linux-android`          |  ✓  |     |     | 32-bit x86 Android         |
| `aarch64-linux-android`       |  ✓  |     |     | ARM64 Android              |
| `arm-unknown-linux-gnueabi`   |  ✓  |  ✓  |     | ARM Linux (2.6.18+)        |
| `arm-unknown-linux-gnueabihf` |  ✓  |  ✓  |     | ARM Linux (2.6.18+)        |
| `aarch64-unknown-linux-gnu`   |  ✓  |     |     | ARM64 Linux (2.6.18+)      |
| `mips-unknown-linux-gnu`      |  ✓  |     |     | MIPS Linux (2.6.18+)       |
| `mipsel-unknown-linux-gnu`    |  ✓  |     |     | MIPS (LE) Linux (2.6.18+)  |
| `powerpc-unknown-linux-gnu`   |  ✓  |     |     | PowerPC Linux (2.6.18+)    |
| `i386-apple-ios`              |  ✓  |     |     | 32-bit x86 iOS             |
| `x86_64-apple-ios`            |  ✓  |     |     | 64-bit x86 iOS             |
| `armv7-apple-ios`             |  ✓  |     |     | ARM iOS                    |
| `armv7s-apple-ios`            |  ✓  |     |     | ARM iOS                    |
| `aarch64-apple-ios`           |  ✓  |     |     | ARM64 iOS                  |
| `i686-unknown-freebsd`        |  ✓  |  ✓  |     | 32-bit FreeBSD             |
| `x86_64-unknown-freebsd`      |  ✓  |  ✓  |     | 64-bit FreeBSD             |
| `x86_64-unknown-openbsd`      |  ✓  |  ✓  |     | 64-bit OpenBSD             |
| `x86_64-unknown-netbsd`       |  ✓  |  ✓  |     | 64-bit NetBSD              |
| `x86_64-unknown-bitrig`       |  ✓  |  ✓  |     | 64-bit Bitrig              |
| `x86_64-unknown-dragonfly`    |  ✓  |  ✓  |     | 64-bit DragonFlyBSD        |
| `x86_64-rumprun-netbsd`       |  ✓  |     |     | 64-bit NetBSD Rump Kernel  |
| `i686-pc-windows-msvc` (XP)   |  ✓  |     |     | Windows XP support         |
| `x86_64-pc-windows-msvc` (XP) |  ✓  |     |     | Windows XP support         |

Tier 3のプラットフォームはここに上げられた物に限るだけでなく、今後も拡張されるでしょう。

## After instllation

Rustをインストールしたら、シェルを開き、次の様にタイプして下さい。

```bash
$ rustc --version
```

これによって、バーションやコミットハッシュ、コミットデータを確認できます。

もし実行できたら、Rustのインストールは成功です！
おめでとう！

もし、Windowsで実行できなかったら、Rustが%PATH%システム変数にある事を確認して下さい。
もしなければ、インストーラーを再実行し、"Change, repair, or remove instllation"の"Change"を選択し、"Add to PATH"がローカルハードディスクにインストールされる様にして下さい。

このインストーラーは、この文書をローカル環境にコピーします。
従って、オフラインで、この文書を読めます。
UNIXシステムは`/usr/local/share/doc/rust`に有り、WindowsではRustをインストールしたディレクトリの`share/doc`ディレクトリに有ります。

また、何か困った事があれば、いくつかの助けを求められる場所があります。
最も簡単なのは[the #rust IRC channel on irc.mozilla.org][irc]で、[Mibbit][mibbit]からアクセスできます。
このリンク先では、Rustacean達とチャットできます。
他のリソースとしては、[the user's forum][usrs]と、[Stack Overflow][stackoverflow]が有ります。

[irc]: irc://irc.mozilla.org/#rust
[mibbit]: http://chat.mibbit.com/?server=irc.mozilla.org&channel=%23rust
[users]: https://users.rust-lang.org/
[stackoverflow]: http://stackoverflow.com/questions/tagged/rust
