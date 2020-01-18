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

int findValue(Node *rootNode,int result,int data){
    
    if(rootNode == NULL){
        return 0;
    }

    findValue(rootNode->left,result,data);

    if(rootNode->data == data){
        result = 1;
        return result;
    }

    return findValue(rootNode->right,result,data);
    
}




int main(){

    
    createBST(10);
    insertNode(root,20);
    insertNode(root,7);
    insertNode(root,17);
    insertNode(root,27);
    insertNode(root,14);

    if(findValue(root,0,27)){
        printf("Element FOund\n");
    }
    else{
        printf("Element Not Found\n");
    }


    return 0;
}