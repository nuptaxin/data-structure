//
// Created by Eric Ren on 2021/10/28.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    int element;
    struct link *next;
} Link;

Link *intLink() {
    Link *p = NULL;
    Link *temp = (Link *) malloc(sizeof(Link));
    temp->element = 1;
    temp->next = NULL;
    p = temp;
    for (int i = 2; i < 6; ++i) {
        Link *a = (Link *) malloc(sizeof(Link));
        a->element = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

void displayLink(Link *temp) {
    while (temp) {
        printf("%d ", temp->element);
        temp = temp->next;
    }
}

int main() {
    Link *p = intLink();
    displayLink(p);
    return 0;
}
