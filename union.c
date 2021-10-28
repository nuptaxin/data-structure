//
// Created by Eric Ren on 2021/10/28.
//
#include <stdio.h>

struct {
    char name[20];
    int flag;
    union {
        int ival;
        float fval;
        char chval;
    } u;
} symtab[2];

int main() {
    symtab[0].u.ival = 6;
    symtab[1].u.fval = 0.7f;
    printf("symtab[0].u.ival:%d,fval:%f,chval:%c\n", symtab[0].u.ival, symtab[0].u.fval, symtab[0].u.chval);
    printf("symtab[1].u.ival:%d,fval:%f,chval:%c\n", symtab[1].u.ival, symtab[1].u.fval, symtab[1].u.chval);
    return 0;
};
