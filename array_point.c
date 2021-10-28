//
// Created by Eric Ren on 2021/10/28.
//
#include <stdio.h>

int a[5] = {1, 2, 3, 4, 5};

void f(int *p, int n) {
    for (int i = 0; i < n; ++i) {
        *(p + i) += 2;
    }
}

int main() {
    printf("原始数组：");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }
    f(a, 5);
    printf("\n修改后数组：");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }
}
