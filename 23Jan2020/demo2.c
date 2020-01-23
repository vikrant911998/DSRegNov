#include<stdio.h>

//Call BY Value
// void swap(int a,int b){
//     int temp = a;
//     a = b;
//     b = temp;

//       printf("Inside Swap A= %d and B= %d\n",a,b);
// }


//Call By reference
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a =10,b=20;
    printf("A= %d and B= %d\n",a,b);

    // swap(a,b);
    swap(&a,&b);

    printf("A= %d and B= %d\n",a,b);

    return 0;
}