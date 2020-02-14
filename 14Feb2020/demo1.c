//Sorting of linked list

#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;


Node * createList(){ 
    Node *start = NULL;
    Node *temp = NULL;
    int value = 0;

    printf("Enter the value\n");
    scanf("%d",&value);

    while(value != -1){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if(start == NULL){
            start = newNode;
            temp = newNode;
        }
        else{
           temp->next = newNode;
           temp = newNode; 
        }
        
        scanf("%d",&value);
    }
    return start;
}

void display(Node *head){
    Node *h = NULL;
    h = head;
    while(h != NULL){
        printf("%d ",h->data);
        h = h->next;
    }
}

void swap(Node *temp1, Node *temp2){
    int t = temp1->data;
    temp1->data = temp2->data;
    temp2->data = t;
}

Node * sort_list(Node *head){
    Node *start = head;
    Node *temp = head;
    Node *last = NULL;

    while(start != last){
        temp = start;
        while(temp->next != last){

            if(temp->data  >  temp->next->data ){
                swap(temp , temp->next);
            }
            temp = temp->next;
        }
        last = temp;
    }
    return start;
}


int main(){
    Node *start = createList();
    
    display(start);
    printf("\n");
    Node *newhead = sort_list(start);

    display(newhead);

    return 0;
}
