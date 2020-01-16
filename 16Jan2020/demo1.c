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

void Inorder(Node *rootNode){

    if(rootNode == NULL){
        return;
    }

    Inorder(rootNode->left);

    printf("%d  ",rootNode->data);

    Inorder(rootNode->right);
}





void Preorder(Node *rootNode){

    if(rootNode == NULL){
        return;
    }

    printf("%d  ",rootNode->data);

    Preorder(rootNode->left);

    Preorder(rootNode->right);
}


void Postorder(Node *rootNode){

    if(rootNode == NULL){
        return;
    }

    Postorder(rootNode->left);

    Postorder(rootNode->right);

    printf("%d  ",rootNode->data);
}


int main(){

    
    createBST(10);
    insertNode(root,20);
    insertNode(root,7);
    insertNode(root,24);
    insertNode(root,45);
    insertNode(root,16);
    insertNode(root,39);

    printf("Inorder Traversal\n");
    Inorder(root);

    printf("\nPostorder Traversal\n");
    Postorder(root);

    printf("\nPreorder Traversal\n");
    Preorder(root);


    return 0;
}