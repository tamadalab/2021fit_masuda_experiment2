# copy

ファイルをコピーするプログラム copy を作成しなさい．
雛形として`main.c`が与えられます．この`main.c`を元に，与えられたそれぞれのステップに取り組んでください．
それぞれのステップを適切に実装できれば，その都度GitHubに変更を push してください．

1. コマンドライン引数に2つのファイル名が与えられます．第１引数で与えられたのファイルの内容を第２引数で与えられたファイルにコピーしなさい．
2. 入力ファイル名が\texttt{-}であった場合は標準入力から受け取り，出力ファイル名が\texttt{-}であった場合，標準出力に出力するようにしなさい．
3. コマンドライン引数にn個のファイルが与えられ，コマンドライン引数の最後にディレクトリ名が指定された場合，n個のファイルを全て最後のディレクトリにコピーしなさい．

## ステップ1

コマンドライン引数に2つのファイル名が与えられます．
第１引数で与えられたのファイルの内容を第２引数で与えられたファイルにコピーしなさい．

### 入出力例

```sh
./copy main.c copied.c # <- main.c の内容を copied.c にコピーする．
diff main.c copied.c   # <- 同じファイルになるため，何も出力しない．
```


## ステップ2

ステップ1の結果を元に，次の処理を追加してください．
入力ファイル名が\texttt{-}であった場合は標準入力から受け取り，出力ファイル名が\texttt{-}であった場合，標準出力に出力するようにしなさい．

### 入出力例

```sh
cat main.c | ./copy - dest.c      # <- 標準入力からの内容（main.c）をdest.cにコピーする．
diff main.c dest.c                # <- 同じファイルになるため，何も出力しない．
./copy main.c - > dest2.c         # <- main.c の内容を標準出力（dest2.c）にコピーする．
diff main.c dest2.c               # <- 同じファイルになるため，何も出力しない．
cat main.c | ./copy - - > dest3.c # copy main.c dest3.c と同様．
diff main.c dest3.c               # <- 同じファイルになるため，何も出力しない．
```

## ステップ3

ステップ2の結果を元に，次の処理を追加してください．
コマンドライン引数にn個のファイルが与えられ，コマンドライン引数の最後にディレクトリ名が指定された場合，n個のファイルを全て最後のディレクトリにコピーしなさい．

### 入出力例

```sh
mkdir dest_dir                      # <- dest_dir ディレクトリを作成する．
./copy main.c README.md dest_dir    # <- main.c, README.md を dest_dir にコピーする．
ls dest_dir
README.md      main.c
./copy main.c README.md missing_dir # <- missing_dirが存在しないので，失敗する．
missing_dir: directory not found.
./copy main.c README.md copy        # <- 最後のファイル（copy）がディレクトリではないので失敗する．
copy: not directory.
```
