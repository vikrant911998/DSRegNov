//BUbble Sort

#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a= *b;
    *b = temp;
}


int main(){
    const int n = 5;
    
    int a[n] = {23,14,5,51,6};
    int i=0,j=0;

    for(i=0 ; i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }

    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}
