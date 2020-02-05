//Insertion Sort

#include<stdio.h>

int main(){
    const int n = 5;
    
    int a[n] = {23,14,5,51,6};
    int i=0,j=0,key=0;

    for(i=1 ; i<n ; i++){
        key = a[i];
        j = i-1;

        while(j>=0  && a[j] > key ){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
    }
    

    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}
