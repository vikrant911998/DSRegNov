#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    char data;
    struct Stack *next;
}Stack;

Stack *top = NULL;

void createStack(char c){
    Stack *temp = (Stack *)malloc(sizeof(Stack));

    temp->data = c;
    temp->next = NULL;
    top = temp;
}

void push(char c){
    Stack *temp = (Stack *)malloc(sizeof(Stack));

    if(temp == NULL){
        // printf("Stack Overflow\n");
        return ;
    }

    temp->data = c;
    temp->next = top;
    top = temp;

}

char pop(){

    if(top == NULL){
        // printf("Stack UnderFlow\n");
        return '\0';
    }

    char c = top->data;
    
    Stack *temp = top;
    top = top->next;

    free(temp);

    return c;
}


char getTop(){
    if(top == NULL){
        // printf("Stack UnderFlow\n");
        return '\0'; 
    }

    char temp = top->data;
    return temp;
}


int main(){
    int i=0,count=0, popcount = 0;

    char str[20] = "{()+[{4}]-([])}}}";

    for( i=0 ; str[i] != '\0' ;i++ ){
        if(str[i]== '{' || str[i]== '[' || str[i]== '(' ){
            count++;
            push(str[i]);
        }


        if(str[i]== '}' || str[i]== ']' || str[i]== ')' ){
            char temp = getTop();

            if(temp == '\0')
                popcount++;
            
            if(temp == '{' && str[i] == '}'){
                count--;
                pop();
                    
            }

            if(temp == '[' && str[i] == ']'){
                count--;
                pop();
            }

            if(temp == '(' && str[i] == ')'){
                count--;
                pop();
            }
        }
    }

    if(!count && !popcount){
       printf("Balanced\n"); 
    }
    else{
        printf("Not Balanced\n");
    }


    return 0;
}
