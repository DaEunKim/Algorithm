//
//  main.cpp
//  BinaryTree
//
//  Created by 김다은 on 2016. 10. 17..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>

typedef struct node{
    char data;
    struct node* leftSubTree;
    struct node* rightSubTree;
}node;

void inOrder(node *root){
    if(root ==NULL)
        return;
    else{
        inOrder(root -> leftSubTree);
        printf("%c ", root->data);
        inOrder(root->rightSubTree);
    }
}
void preOrder(node *root){
    if(root ==NULL)
        return;
    else{
        printf("%c ", root->data);
        preOrder(root -> leftSubTree);
        preOrder(root->rightSubTree);
    }
}
void postOrder(node *root){
    if(root ==NULL)
        return;
    else{
        postOrder(root -> leftSubTree);
        postOrder(root->rightSubTree);
        printf("%c ", root->data);
        
    }
}

int size(struct node *root){
    if(root ==NULL)
        return 0;
    return size(root->leftSubTree)+size(root->rightSubTree)+1;
}
int height(struct node *root){
    if(root == NULL)
        return -1;
    int left = height(root->leftSubTree);
    int right = height(root->rightSubTree);
    return left>right? left+1:right+1;
}
void mirror(struct node *root){
    if(root ==NULL)
        return ;
    mirror(root->leftSubTree);
    mirror(root->rightSubTree);
    std::swap(root->leftSubTree, root->rightSubTree);
}
//void swap(node *l, node *r){
//    node *tmp = l;
//    l=r;
//    r=tmp;
//}

int main(void){
    node *treeA = (node*)malloc(sizeof(node));
    node *treeB = (node*)malloc(sizeof(node));
    node *treeC = (node*)malloc(sizeof(node));
    node *treeD = (node*)malloc(sizeof(node));
    node *treeE = (node*)malloc(sizeof(node));
    node *treeF = (node*)malloc(sizeof(node));
    node *treeG = (node*)malloc(sizeof(node));
    treeA->data = 'A';
    treeB->data = 'B';
    treeC->data = 'C';
    treeD->data = 'D';
    treeE->data = 'E';
    treeF->data = 'F';
    treeG->data = 'G';
    treeA->leftSubTree = treeB;
    treeA->rightSubTree = treeC;
    
    treeB->leftSubTree = treeD;
    treeB->rightSubTree = NULL;
    
    treeD->rightSubTree = treeG;
    treeD->leftSubTree = NULL;
    
    treeC->leftSubTree = treeE;
    treeC->rightSubTree = treeF;
    
    treeE->leftSubTree = NULL;
    treeE->rightSubTree = NULL;
    
    treeF->leftSubTree = NULL;
    treeF->rightSubTree = NULL;
    
    treeG->leftSubTree = NULL;
    treeG->rightSubTree = NULL;
    
    inOrder(treeA);
    printf("\n%d\n%d\n", size(treeA), height(treeA));
    mirror(treeA);
    inOrder(treeA);
    mirror(treeA);
    
    puts(" \n");
    
    preOrder(treeA);
    printf("\n%d\n%d\n", size(treeA), height(treeA));
    mirror(treeA);
    preOrder(treeA);
    mirror(treeA);
    
    puts(" \n");
    
    postOrder(treeA);
    printf("\n%d\n%d\n", size(treeA), height(treeA));
    mirror(treeA);
    postOrder(treeA);
    mirror(treeA);
    
    
}
