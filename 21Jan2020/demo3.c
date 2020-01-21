//Iterative Inorder

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

void IterativeInorder(Node *rootNode){
    Node *temp = rootNode;

    while(temp != NULL || !isEmpty()){

        while(temp != NULL){
            push(temp);
            temp = temp->left;
        }

        Node *temp1 = getTop();
        printf("%d  ",temp1->data);
        pop();

        temp = temp->right;
    }
    
}