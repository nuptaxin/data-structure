//
// Created by Eric Ren on 2021/11/1.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct biNode {
    int element;
    struct biNode *lchild, *rchild;
} BiNode, *BiTree;

int top = -1;
BiTree a[10];

void createBiTree(BiNode **biNode) {
    *biNode = (BiTree) malloc(sizeof(BiNode));
    BiTree biTree = *biNode;
    biTree->element = 1;

    biTree->lchild = (BiTree) malloc(sizeof(BiNode));
    biTree->lchild->element = 2;

    biTree->lchild->lchild = (BiTree) malloc(sizeof(BiNode));
    biTree->lchild->lchild->element = 4;
    biTree->lchild->lchild->lchild = NULL;
    biTree->lchild->lchild->rchild = NULL;
    biTree->lchild->rchild = (BiTree) malloc(sizeof(BiNode));
    biTree->lchild->rchild->element = 5;
    biTree->lchild->rchild->lchild = NULL;
    biTree->lchild->rchild->rchild = NULL;

    biTree->rchild = (BiTree) malloc(sizeof(BiNode));
    biTree->rchild->element = 3;

    biTree->rchild->lchild = (BiTree) malloc(sizeof(BiNode));
    biTree->rchild->lchild->element = 6;
    biTree->rchild->lchild->lchild = NULL;
    biTree->rchild->lchild->rchild = NULL;
    biTree->rchild->rchild = (BiTree) malloc(sizeof(BiNode));
    biTree->rchild->rchild->element = 7;
    biTree->rchild->rchild->lchild = NULL;
    biTree->rchild->rchild->rchild = NULL;
}

void printBiTree(BiTree biTree) {
    printf("%d ", biTree->element);
}

void middleOrder(BiTree biTree) {
    if (biTree) {
        middleOrder(biTree->lchild);
        printBiTree(biTree);
        middleOrder(biTree->rchild);
    }
}

BiTree pop() {
    if (top == -1) {
        return NULL;
    }
    return a[top--];
}

void push(BiTree biTree) {
    a[++top] = biTree;
}

void middleOrderNoRecursion(BiTree biTree) {
    int popFlag = 0;
    while (biTree) {
        if (popFlag) {
            printBiTree(biTree);
            if (biTree->rchild) {
                biTree = biTree->rchild;
                popFlag = 0;
            } else {
                biTree = pop();
                popFlag = 1;
            }
        } else {
            push(biTree);
            if (biTree->lchild) {
                biTree = biTree->lchild;
                popFlag = 0;
            } else {
                biTree = pop();
                popFlag = 1;
            }
        }
    }
}

int main() {
    BiTree biTree;
    createBiTree(&biTree);
    //printBiTree(biTree->lchild->lchild);
    middleOrder(biTree);
    middleOrderNoRecursion(biTree);
    return 0;
}