//Modulo-Division Method ->Hashing Method
#include<stdio.h>

int main(){
    int a[5] = {171,223,67,89,5};
    int size = 5;
    int b[10] = {0}; 
    int index =0,i=0;

    for(i=0 ; i<5 ; i++){
        index = a[i]%size;
        b[index] = a[i];
    }

    int num =0 ;
    printf("Enter the Number to be searched\n");
    scanf("%d",&num);

    printf("Element = %d\n",b[num%size]);


    return 0;
}