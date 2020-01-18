//Sum of Last N Nodes

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

Stack *stack = NULL;

void createStack(){
    stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
}

void push(int element){
    Node *temp = (Node *)malloc(sizeof(Node));
    
    if(temp == NULL){
       printf("Stack Overflow\n"); 
    }
    else if(stack->top == NULL){
        temp->data = element;
        temp->next = NULL;
        stack->top = temp;
    }
    else{

        Node *temp1 = stack->top;
        temp->data = element;
        temp->next = temp1;
        stack->top = temp;
    }
    
}

int pop(){
    Node *temp;
    int data;

    if(stack->top == NULL){
        printf("Stakc Underflow\n");
        return 0;
    }
    else{
        temp = stack->top;
        stack->top = stack->top->next; //stack->top = temp->next;
        data = temp->data;
        free(temp);
    }

    return data;
}

int peek(){
    int data;
    if(stack->top == NULL){
       printf("Stakc Underflow\n");
        return 0; 
    }
    else{
        data = stack->top->data;
    }

    return data;
}

bool isEmpty(){
    if(stack->top == NULL){
        return true;
    }
    else{
        return false;
    }
}


void display(){
    Node *head = stack->top;

    while(head != NULL){
        printf("%d  ",head->data);
        head = head->next;
    }
}


int main(){
    createStack();

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);

    int n=0;
    printf("Enter the value of n\n");
    scanf("%d",&n);

    int i=1,sum=0;
    while(i<=n){
        
        sum = sum + pop();
    }

    printf("Sum = %d\n",sum);

    return 0;
}

