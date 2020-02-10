//Quick Sort

#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a,int low, int high){
    int pivot = a[high];

    int i = low-1;
    int j;
    for( j=low ; j<=high-1 ; j++){
        if( a[j] < pivot ){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);

    return (i+1);
}


void quick_Sort(int *a,int low, int high){
    
    if(low < high){

        int pi = partition(a,low,high);

        quick_Sort(a,low,pi-1);
        quick_Sort(a,pi+1,high);
    }
}


int main(){
    int a[] = {38,27,43,3,9,21,67,91,102,39};

    quick_Sort(a,0,9);
    
    int i=0;
    for(i=0;i<10;i++){
        printf("%d  ",a[i]);
    }
    printf("\n");

    return 0;
}