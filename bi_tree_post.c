//
// Created by Eric Ren on 2021/11/2.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct biNode {
    int element;
    struct biNode *lchild, *rchild;
} BiNode, *BiTree;

typedef struct stNode {
    BiTree biTree;
    // 记录右孩子是否需要遍历。0：不需要，1：需要
    int tag;
} StNode;

StNode a[10];
int top = -1;

void initBiTree(BiNode **tree) {
    *tree = (BiTree) malloc(sizeof(BiNode));
    BiTree biTree = *tree;
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

void printPost(BiTree biTree) {
    if (biTree) {
        printPost(biTree->lchild);
        printPost(biTree->rchild);
        printBiTree(biTree);
    }
}

void push(StNode stNode) {
    a[++top] = stNode;
}

StNode pop() {
    if (top != -1) {
        return a[top--];
    }
    StNode *stNode = (StNode *) malloc(sizeof(StNode));
    stNode->biTree = NULL;
    return *stNode;
}

void printPostNoRecursion(BiTree biTree) {
    int popFlag = 0;
    StNode *stNode = (StNode *) malloc(sizeof(StNode));
    stNode->biTree = biTree;
    stNode->tag = 0;
    push(*stNode);
    while (stNode->biTree) {

        if (popFlag) {
            if (stNode->tag == 0) {
                printBiTree(stNode->biTree);
                *stNode = pop();
                popFlag = 1;
            } else {
                if (!stNode->biTree->rchild && !stNode->biTree->lchild) {
                    printBiTree(stNode->biTree);
                    *stNode = pop();
                    popFlag = 1;
                    continue;
                }
                if (stNode->biTree->rchild || stNode->biTree->lchild) {
                    stNode->tag = 0;
                    push(*stNode);
                }
                if (stNode->biTree->rchild) {
                    StNode *stNodeChild = (StNode *) malloc(sizeof(StNode));
                    stNodeChild->biTree = stNode->biTree->rchild;
                    stNodeChild->tag = 1;
                    push(*stNodeChild);
                }
                if (stNode->biTree->lchild) {
                    StNode *stNodeChild = (StNode *) malloc(sizeof(StNode));
                    stNodeChild->biTree = stNode->biTree->lchild;
                    stNodeChild->tag = 0;
                    push(*stNodeChild);
                    stNode->biTree = stNode->biTree->lchild;
                    popFlag = 0;
                } else {
                    *stNode = pop();
                    popFlag = 1;
                }
            }
        } else {
            if (stNode->biTree->rchild) {
                StNode *stNodeChild = (StNode *) malloc(sizeof(StNode));
                stNodeChild->biTree = stNode->biTree->rchild;
                stNodeChild->tag = 1;
                push(*stNodeChild);
            }
            if (stNode->biTree->lchild) {
                StNode *stNodeChild = (StNode *) malloc(sizeof(StNode));
                stNodeChild->biTree = stNode->biTree->lchild;
                stNodeChild->tag = 0;
                push(*stNodeChild);
                stNode->biTree = stNode->biTree->lchild;
                popFlag = 0;
            } else {
                *stNode = pop();
                popFlag = 1;
            }
        }
    }
}

int main() {
    BiTree biTree;
    initBiTree(&biTree);
    //printBiTree(biTree->lchild->lchild);
    printPost(biTree);
    printf("\n");
    printPostNoRecursion(biTree);
    return 0;
}
