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

Node * minValueNode(Node* node) 
{ 
    Node* current = node; 
  
    
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 


Node * deleteNode(Node *rootNode,int data){

    if(rootNode == NULL){
        return NULL;
    }

    if(data < rootNode->data){
        rootNode->left = deleteNode(rootNode->left,data);
        
    }

    if(data > rootNode->data){
        rootNode->right = deleteNode(rootNode->right,data);
        
    }
    
    if(data == rootNode->data){
        
        if (rootNode->left == NULL) 
        { 
            Node *temp = rootNode->right; 
            free(rootNode); 
            return temp; 
        } 
        else if (rootNode->right == NULL) 
        { 
            Node *temp = rootNode->left; 
            free(rootNode); 
            return temp; 
        }  

        Node* temp = minValueNode(root->right); 
  
       
        rootNode->data = temp->data; 
  
       
        rootNode->right = deleteNode(rootNode->right, temp->data);   

    }

    return rootNode;
}


int main(){

    
    createBST(50);
    insertNode(root,30);
    insertNode(root,20);
    insertNode(root,40);
    insertNode(root,70);
    insertNode(root,60);
    insertNode(root,80);
    

    Node *root1 = root;
    Inorder(root1);

    printf("\n");

    Node *newRoot = deleteNode(root1,20);

    Inorder(newRoot);

   
    return 0;
}