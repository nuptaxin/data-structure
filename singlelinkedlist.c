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
    printf("\n");
}

void insertElement(Link *p, int index, int value) {
    int start = 0;
    while (start < index - 1) {
        p = p->next;
        start++;
    }
    Link *temp = (Link *) malloc(sizeof(Link));
    temp->element = value;
    temp->next = p->next;
    p->next = temp;
}

void deleteElement(Link *p, int index) {
    int start = 0;
    while (start < index - 1) {
        p = p->next;
        start++;
    }
    Link *temp = p->next;
    p->next = temp->next;
    free(temp);

}

int searchElement(Link *p, int element) {
    int index = 0;
    while (p->element != element) {
        p = p->next;
        index++;
    }
    if (p->next != NULL) {
        return index;
    }
    return -1;
}

void updateElement(Link *p, int index, int value) {
    int start = 0;
    while (start < index) {
        p = p->next;
        start++;
    }
    p->element = value;
}

int main() {
    Link *p = intLink();
    displayLink(p);
    insertElement(p, 1, 11);
    displayLink(p);
    deleteElement(p, 4);
    displayLink(p);
    printf("search 3 index:%d\n", searchElement(p, 3));
    updateElement(p, 2, 22);
    displayLink(p);
    return 0;
}
