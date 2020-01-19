//Height of the BST

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


int height(Node *rootNode){

    if(rootNode == NULL){
        return 0;
    }
    else{
        int leftHeight = height(rootNode->left);
        int rightHeight = height(rootNode->right);

        if(leftHeight > rightHeight){
            return leftHeight+1;
        }
        else{
            return rightHeight+1;
        }
    }
}


int main(){

    // 10,7,20,17,45,16,39
    
    createBST(10);
    insertNode(root,20);
    insertNode(root,7);
    insertNode(root,17);
    insertNode(root,45);
    insertNode(root,16);
    insertNode(root,39);

    printf("Max height = %d\n",height(root));
    

    return 0;
}