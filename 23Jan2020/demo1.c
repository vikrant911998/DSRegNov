#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

typedef struct Stack{
    Node *node;
    struct Stack *next;
}Stack;

Stack *top = NULL;

void push(Node *node1){

    Stack *temp = (Stack *)malloc(sizeof(Stack));
    
    if(!temp){
        printf("Stack Overflow\n");
        return ;
    }
    if(top == NULL){
        temp->node = node1;
        temp->next = NULL;
        top = temp;
        return ;
    }

    temp->node = node1;
    temp->next = top;
    top = temp;

}


Node *pop(){
    if(top ==  NULL){
        printf("Stack Underflow\n");
        return NULL;
    }

    Node *t = top->node;
    top = top->next;

    return t;
}

Node *getTop(){
    if(top ==  NULL){
        printf("Stack Underflow\n");
        return NULL;
    }

    Node *t = top->node;

    return t;
}

bool empty(){
    return (top == NULL);
}

Node * createNode(int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void display(){
    if(top == NULL){
        return ;
    }

    Stack *temp = top;

    while(temp != NULL){
        printf("%d  ",temp->node->data);
        temp = temp->next;
    }
}


int main(){
    Node *n1 = createNode(10);
    Node *n2 = createNode(20);
    Node *n3 = createNode(30);
    Node *n4 = createNode(40);


    push(n1);
    push(n2);
    push(n3);
    push(n4);

    display();
    printf("\n");

    pop();
    pop();

    display();
    printf("\n");


    return 0;
}