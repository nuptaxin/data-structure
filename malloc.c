//
// Created by Eric Ren on 2021/10/28.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    char c = 'a';
    char *p = &c;
    int *y;
    y = (int *) malloc(sizeof(int));
    *y = 10;
    printf("*y:%d,*p:%c\n", *y, *p);
    free(y);
    *y = 1024;
    printf("内存释放后(其实这只是一个系统逻辑问题，如果不处理仍然可以随意乱用的)：*y:%d,*p:%c\n", *y, *p);
    return 0;
}
