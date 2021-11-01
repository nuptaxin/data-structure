//
// Created by Eric Ren on 2021/11/1.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct biNode {
    int element;
    struct biNode *lchild, *rchild;
} BiNode, *BiTree;

BiTree createBiTree() {
    BiTree biTree = (BiNode *) malloc(sizeof(BiNode));
    biTree->element = 1;
    biTree->lchild = (BiNode *) malloc(sizeof(BiNode));
    biTree->lchild->element = 2;
    biTree->lchild->lchild = (BiNode *) malloc(sizeof(BiNode));
    biTree->lchild->lchild->element = 4;
    biTree->lchild->lchild->lchild = NULL;
    biTree->lchild->lchild->rchild = NULL;
    biTree->lchild->rchild = (BiNode *) malloc(sizeof(BiNode));
    biTree->lchild->rchild->element = 5;
    biTree->lchild->rchild->lchild = NULL;
    biTree->lchild->rchild->rchild = NULL;
    biTree->rchild = (BiNode *) malloc(sizeof(BiNode));
    biTree->rchild->element = 3;
    biTree->rchild->lchild = (BiNode *) malloc(sizeof(BiNode));
    biTree->rchild->lchild->element = 6;
    biTree->rchild->lchild->lchild = NULL;
    biTree->rchild->lchild->rchild = NULL;
    biTree->rchild->rchild = (BiNode *) malloc(sizeof(BiNode));
    biTree->rchild->rchild->element = 7;
    biTree->rchild->rchild->lchild = NULL;
    biTree->rchild->rchild->rchild = NULL;
    return biTree;
}

void displayElement(BiTree biTree) {
    printf("%d ", biTree->element);
}

//递归实现
void preOrder(BiTree biTree) {
    if (biTree) {
        displayElement(biTree);
        preOrder(biTree->lchild);
        preOrder(biTree->rchild);
    }
}

//非递归实现，思路：利用栈，每次输出当前元素，右元素进栈，左元素为下一个输出。直到找不到左元素，然后从栈中依次取出元素。
BiTree pop(BiTree *a, BiTree nullNode) {
    BiTree noNullBiTree = NULL;
    for (int i = 0; i < 10; i++) {
        if (a[i]->element != -1) {
            noNullBiTree = a[i];
        } else {
            if (i != 0) {
                a[i - 1] = nullNode;
            }
            return noNullBiTree;
        }
    }
    return noNullBiTree;
}

void push(BiTree biTree, BiNode **a) {
    for (int i = 0; i < 10; i++) {
        if (a[i]->element == -1) {
            a[i] = biTree;
            return;
        }
    }
}

void preOrderNoRecursion(BiTree biTree) {
    BiTree a[10];
    BiTree nullNode = (BiNode *) malloc(sizeof(BiNode));
    nullNode->element = -1;
    for (int i = 0; i < 10; ++i) {
        a[i] = nullNode;
    }

    while (biTree) {
        displayElement(biTree);
        if (biTree->rchild) {
            push(biTree->rchild, a);
        }
        if (biTree->lchild) {
            biTree = biTree->lchild;
        } else {
            biTree = pop(a, nullNode);
        }
    }
}


int main() {
    BiTree tree = createBiTree();
    printf("根的左子树的左子树的值：%d\n", tree->rchild->rchild->element);
    preOrder(tree);
    printf("\n");
    preOrderNoRecursion(tree);
    return 0;
}
