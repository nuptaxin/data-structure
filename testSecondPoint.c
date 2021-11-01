//
// Created by Eric Ren on 2021/11/1.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct biNode {
    int element;
} BiNode;

void print1(int **qb) {
    printf("二级指针直接取下标111:%d\n", qb[4]);
    //printf("二级指针求解再直接取下标111:%d\n", (*qb)[2].element);
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;
    int **q = &p;
    printf("a的地址:%x\n", &a);
    printf("a的地址,直接用字母:%x\n", a);
    printf("p的地址:%x,p的值:%x,p的求解:%d\n", &p, p, *p);
    printf("q的地址:%x,q的值:%x,q的求解:%x,q的求解*2:%x\n", &q, q, *q, **q);
    printf("一级指针直接取下标:%d\n", p[2]);
    printf("二级指针直接取下标:%x\n", q[0]);
    printf("二级指针求解再直接取下标:%d\n", (*q)[2]);

    //数组为struct的情况
    BiNode b[5];
    for (int i = 0; i < 5; ++i) {
        b[i] = *(BiNode *) malloc(sizeof(BiNode));
        b[i].element = i;
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d", b[i].element);
    }
    printf("\n");
    int *pb = b;
    int **qb = &pb;
    printf("一级指针直接取下标:%d\n", pb[2]);
    printf("二级指针直接取下标:%d\n", qb[2]);
    printf("二级指针求解再直接取下标:%d\n", (*qb)[2]);
    print1(a);
    return 0;
}