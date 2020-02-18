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


int main(){
    Node *h1 = createList();
    Node *h2 = createList();
    Node *result = NULL;

    Node *temp1 = h1,*temp2 = h2,*temp3 = NULL;

    while(temp1 != NULL && temp2 != NULL){

        if(temp1->data == temp2->data){
            
            if(result == NULL){
                result = temp1;
                temp3 = temp1;
            }
            else{
                temp3->next = temp1;
                temp3 = temp3->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if(temp1->data < temp2->data){
            temp1 = temp1->next;
        }
        else{
            temp2 = temp2->next;
        }
    }

    display(result);

    return 0;
}
