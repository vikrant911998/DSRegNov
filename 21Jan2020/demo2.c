//Iterative PreOrder

#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node *right;
    struct Node *left;
}Node;

Node *root = NULL;

void createBST(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    root = newNode;
}

void insertNode(Node *rootNode, int data){

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(rootNode->right == NULL && data > rootNode->data){
        rootNode->right = newNode;
        return ;
    }

    if(rootNode->left == NULL && data < rootNode->data){
        rootNode->left = newNode;
        return ;
    }

    if( data > rootNode->data){
        insertNode(rootNode->right,data);
    }
    else{
        insertNode(rootNode->left,data);
    }

}


void IterativePreorder(Node *rootNode){
    push(rootNode);

    while(!isEmpty()){
        Node *temp = getTop();
        printf("%d  ",temp->data);
        pop();

        if(temp->right){
            push(temp->right);
        }
        if(temp->left){
            push(temp->left);
        }
    }
}