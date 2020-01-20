//Iterative PostOrder.


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

void IterativePostorder(Node *rootNode){
    Stack s1,s2;

    s1.push(rootNode);
    Node *temp;

    while(!s1.empty()){
        temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }

    while(!s2.empty()){
        temp = s2.top();
        s2.pop();
        printf("%d  ",temp->data);
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

    return 0;
}
