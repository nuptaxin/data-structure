//
// Created by Eric Ren on 2021/10/28.
//
#include <stdio.h>

int m, n, a[100][100];

void initArray() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
}

void printArray() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

void transposition() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m >= n && i > j || m < n && i < j) {
                int k = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = k;
            }
        }
    }
    if (m != n) {
        int k = m;
        m = n;
        n = k;
    }
}

int main() {
    printf("输入矩阵的行数m(0<m<100):");
    scanf("%d", &m);
    printf("输入矩阵的列数n(0<n<100):");
    scanf("%d", &n);
    printf("请依次输入%d*%d矩阵的所有%d个元素：\n", m, n, m * n);
    initArray();
    printf("输出原始矩阵:\n");
    printArray();
    transposition();
    printf("输出转置后矩阵:\n");
    printArray();
    return 0;
}



