//Mirror Tree

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;
Node *root = NULL;

void mirror_tree(Node *rootNode){
    if(rootNode == NULL){
        return ;
    }
    else{
        mirror_tree(rootNode->left);
        mirror_tree(rootNode->right);

        Node *temp = rootNode->left;
        rootNode->left = rootNode->right;
        rootNode->right = temp;
    }
}

void inorder(Node *rootNode){
    if(rootNode == NULL){
        return;
    }
    
    inorder(rootNode->left);
    printf("%d  ",rootNode->data);
    inorder(rootNode->right);
}

Node * createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main(){
    Node *n1 = createNode(1);
    Node *n2 = createNode(2);
    Node *n3 = createNode(3);
    Node *n4 = createNode(4);
    Node *n5 = createNode(5);

    n1->left = n3;
    n1->right = n2;
    n2->left = n5;
    n2->right = n4;

    root = n1;
    mirror_tree(root);
    inorder(root);


    return 0;
}