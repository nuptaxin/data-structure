//
// Created by Eric Ren on 2021/10/28.
//
#include <stdio.h>

void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap3(int *a, int *b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a, b;
    a = 3;
    b = 4;
    printf("a=%d,b=%d\n", a, b);
    a = 3;
    b = 4;
    swap1(a, b);
    printf("swap1【NO】:a=%d,b=%d\n", a, b);
    a = 3;
    b = 4;
    swap2(&a, &b);
    printf("swap2【YES】:a=%d,b=%d\n", a, b);
    a = 3;
    b = 4;
    swap3(a, b);
    printf("swap3【NO】:a=%d,b=%d\n", a, b);
}


