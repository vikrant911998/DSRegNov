//Recursive Search and Iterative Search


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


int IterativeSearch(Node *rootNode,int data){

    while(rootNode != NULL){
        
        if(rootNode->data == data){
            return 1;
        }
        if(data < rootNode->data){
            rootNode = rootNode->left;
        }

        if(data > rootNode->data){
            rootNode = rootNode->right;
        }
    }

    return 0;
}


int RecursiveSearch(Node *rootNode,int data){
    if(rootNode == NULL){
        return 0;
    }
    if(rootNode->data == data){
        return 1;
    }
    if(data < rootNode->data){
        return RecursiveSearch(rootNode->left,data);
    }
    else{
        return RecursiveSearch(rootNode->right,data);
    }
}



int main(){

    
    createBST(10);
    insertNode(root,20);
    insertNode(root,7);
    insertNode(root,17);
    insertNode(root,45);
    insertNode(root,16);
    insertNode(root,39);


    // if( IterativeSearch(root,99) ){
    //     printf("Element Found\n");
    // }
    // else{
    //     printf("Element Not Found\n");
    // }

    if( RecursiveSearch(root,45) ){
        printf("Element Found\n");
    }
    else{
        printf("Element Not Found\n");
    }

    return 0;
}