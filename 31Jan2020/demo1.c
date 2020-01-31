#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

typedef struct Queue{
    Node *value;
    struct Queue *next;
}Queue;

Queue *front = NULL;
Queue *rear = NULL;


void enqueue(Node *value){
    Queue *temp = (Queue *)malloc(sizeof(Queue));
    temp->value = value;
    temp->next = NULL;

    if(rear == NULL){
        front = temp;
        rear = temp;
        return ;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue(){
    Node *temp = NULL;

    if(front == NULL){
        printf("Queue is Empty\n");
        return ;
    }

    if(front == rear){
        temp = front->value;
        front = NULL;
        rear = NULL;
        free(temp);
        return ;
    }

    temp = front->value;
    front = front->next;
    free(temp);
}

Node *getFront(){
     Node *temp = NULL;

    if(front == NULL){
        printf("Queue is Empty\n");
        return NULL;
    }

    if(front == rear){
        temp = front->value;
        return  temp;
    }

    temp = front->value;
    return temp;
}


Node *root = NULL;

void createBST(int data){
    root = (Node *)malloc(sizeof(Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;

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


void levelOrder(Node *rootNode){
    if(rootNode == NULL){
        return;
    }

    enqueue(rootNode);

    while(front != NULL){
        Node *temp = getFront();
        printf("%d   ",temp->data);
        dequeue();


        if(temp->left != NULL){
            enqueue(temp->left);
        }
        if(temp->right != NULL){
            enqueue(temp->right);
        }
    }
}

int main(){
    createBST(10);
    insertNode(root,7);
    insertNode(root,20);
    insertNode(root,17);
    insertNode(root,45);
    insertNode(root,16);
    insertNode(root,39);
    
    levelOrder(root);

    return 0;
}