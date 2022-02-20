# gcc_programing
ふつうのLinuxプログラミングの勉強の記録

## ss5

練習問題

1) catコマンドをstdinを対応させる。=> ok


2) 行数カウント                    => ok

## ss6

練習問題

1) catコマンドの改造 => まだ


2) 行数カウント => ファイル末端の改行がわからない


3) fread, fwriteでcatを実装 => freadがわからずまともに動かない

## ss7 headコマンドを作る

ファイルから読み込ませるまでは行けたが、オプションのAPIで詰まった。

ただのカッコ忘れでした。

## ss8 grepコマンドを作る

そこまで困らず行けた。

## ss9

特にコードを書くことはなかった。

## ss10

lsコマンドは特に困らず行けた

mkdir, rmdirコマンドもok

ハードリンク、シンボリックリンクもok

stat,chmodもok

## ss11

malloc() calloc() realloc()などのAPIを使った。

## ss12

ふつうにfork()、wait()するのはできた。一方ダブルforkはうまく動かな買った。


popen(),pclose()パイプを作るのはできた。一方、fork(),pipe()の方法
はうまく動かなかった。dup()で作る方はわからなかった。 

## ss13

APIは理解したが使い方がいまいち

## ss14

pwdコマンドはok


