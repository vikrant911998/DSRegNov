//Recursive Bubble Sort

#include<stdio.h>

void swapping(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int a[],int n){
    if(n == 1){
        return ;
    }
    int i=0;
    for( i=0; i<n-1 ; i++ ){
        if(a[i] > a[i+1]){
            swapping(&a[i],&a[i+1]);
        }
    }

    bubble(a,n-1);
}

int main(){
    int a[7]={5, 1, 4, 2, 8,11, 2};

    bubble(a,7);

    int i=0;
    for(i=0;i<7;i++){
        printf("%d  ",a[i]);
    }

    return 0;
}