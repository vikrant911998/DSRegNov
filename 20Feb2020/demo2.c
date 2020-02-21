//Collision Handling -> Separate Chaining Method
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *create(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int main(){
    int a[5] = {15,85,33,58,12};
    int size = 5,temp = 0;
    Node *arr[10];
    int i=0;
    for(i=0;i<10;i++){
        arr[i] = NULL;
    }


    for(i=0;i<5;i++){
        Node *newNode = create(a[i]);
        temp = a[i] % size;

        if( arr[temp] == NULL ){
            arr[ temp ] = newNode;
        }
        else {
            Node *t = arr[ temp ];
            while(t->next != NULL){
                t = t->next;
            }
            t->next = newNode;
        }
    }

    int num = 0;
    printf("Enter the Number to be searched\n");
    scanf("%d",&num);

    Node *head = arr[ (num%size) ];

    while(head != NULL){
        if(head->data == num){
            printf("Element  = %d\n",head->data);
            break;
        }
        head = head->next;
    }



    return 0;
}