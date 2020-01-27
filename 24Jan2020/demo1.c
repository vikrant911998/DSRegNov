//Queue for value(Node *) type using Queue Wrapper.
//Queue -> Node * -> BSTNode * -> data

#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode{
    int data;
    struct BSTNode *left,*right;
}BSTNode;

typedef struct Node{
    BSTNode *value;
    struct Node *next;
}Node;

typedef struct Queue{
    Node *front;
    Node *rear;
}Queue;

Queue *queue = NULL;

void createQueue(){
    Queue *temp = (Queue *)malloc(sizeof(Queue));
    temp->front = NULL;
    temp->rear = NULL;
    queue = temp;

    // Queue *temp1 = (Queue *)malloc(sizeof(Queue));
    // temp1->front = NULL;
    // temp1->rear = NULL;
    // queue1 = temp1;
}


void enqueue(Node *node){
    if(queue->rear == NULL && queue->front == NULL){
        queue->front = node;
        queue->rear = node;
        return ;
    }

    queue->rear->next = node;
    queue->rear = node;
}

Node * dequeue(){
    Node *temp = NULL;

    if(queue->front == NULL){
        printf("Queue is Empty\n");
        return NULL;
    }
    if(queue->front == queue->rear){
        temp = queue->front;
        queue->front = NULL;
        queue->rear = NULL;
        return temp;
    }

    temp = queue->front;
    queue->front = queue->front->next;

    return temp;
}

Node *getFront(){
    Node *temp = NULL;

    if(queue->front == NULL){
        printf("Queue is Empty\n");
        return NULL;
    }

    temp = queue->front;

    return temp;
}

void display(){
    Node *temp = queue->front;

    while (temp != NULL)
    {
        printf("%d  ",temp->value->data);
        temp = temp->next;
    }
    

}

Node *createNode(BSTNode *value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;

    return temp;
}

BSTNode *createBSTNode(int data){
    BSTNode *temp = (BSTNode *)malloc(sizeof(BSTNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int main(){
    createQueue();
    enqueue( createNode( createBSTNode(10) ) );
    enqueue( createNode( createBSTNode(20) ) );
    enqueue( createNode( createBSTNode(30) ) );
    enqueue( createNode( createBSTNode(40) ) );
    enqueue( createNode( createBSTNode(50) ) );

    display();

    printf("\n");

    dequeue();
    dequeue();

    display();
    printf("\n");   


    return 0;
}