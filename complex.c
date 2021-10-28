//
// Created by Eric Ren on 2021/10/27.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct complex{
    float x,y;
} Complex;
Complex CreateComp(float x, float y){
    Complex complex;
    complex.x = x;
    complex.y = y;
    return complex;
}
Complex AddComp(Complex a, Complex b){
    Complex c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}
void PrintComp(Complex complex){
    printf("%3.2f+%3.2fi\n", complex.x, complex.y);
}
int main(){
    Complex a,b,c;
    a = CreateComp(1.0f, 2.0f);
    b = CreateComp(3.0f, 4.0f);
    c = AddComp(a, b);
    PrintComp(a);
    PrintComp(b);
    PrintComp(c);
    return 0;
}
