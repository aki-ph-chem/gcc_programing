
// ...は可変引数の宣言
static void log_exit(char* fmt,...){

    // (1) va_listの宣言
    va_list ap;

    // (2) 使う前に呼ぶ
    va_start(ap,fmt);
    // (3) va_listを使う
    vprintf(stderr,fmt,ap);
    fputc('\n',stderr);
    // (4) 使た後に呼ぶ
    va_end(ap);
    exit(1);
}
