//
// Created by Eric Ren on 2021/10/27.
//
#include <stdio.h>

typedef struct complex {
    float x, y;
} Complex;

Complex createComplex(float x, float y) {
    Complex complex;
    complex.x = x;
    complex.y = y;
    return complex;
}

Complex addComplex(Complex a, Complex b) {
    Complex c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

void printComplex(Complex complex) {
    printf("%3.2f+%3.2fi\n", complex.x, complex.y);
}

int main() {
    Complex a, b, c;
    a = createComplex(1.0f, 2.0f);
    b = createComplex(3.0f, 4.0f);
    c = addComplex(a, b);
    printComplex(a);
    printComplex(b);
    printComplex(c);
    return 0;
}
