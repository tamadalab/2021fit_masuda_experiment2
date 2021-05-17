#include <stdio.h>

void print_help() {
    printf("copy <INPUT_FILE> <OUTPUT_FILE>\n\
copy <INPUT_FILEs...> <DIR>\n\
INPUT_FILE     入力ファイル．- の場合は標準入力．\n\
OUTPUT_FILE    出力ファイル．- の場合は標準出力．\n\
DIR            ファイルのコピー先のディレクトリ．\n");
}
void copy_impl(FILE *from, FILE *to) {
    // この関数を実装する．
}
int copy(char *from_file, char *to_file) {
    FILE *from = // 読み込み専用でファイルを開く．
    if(from == NULL){
        perror(from_file);
        return 1;
    }
    FILE *to =   //  書き込み専用でファイルを開く．    
    if(to == NULL){
        perror(to_file);
        return 2;
    }
    copy_impl(from, to);
    if(from != NULL) {
        fclose(from);
    }
    if(to != NULL) {
        fclose(to);
    }
    return 0;
}
int perform(int argc, char *argv[]) {
    if(argc == 3) {
        return copy(argv[1], argv[2]);
    }
    print_help();
    return 0;
}
int main(int argc, char *argv[]) {
    int status = perform(argc, argv);
    return status;
}
