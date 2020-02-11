//Deletion in Between in Heap.

#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 2147483

typedef struct MaxHeap{
    int *arr;
    int capacity;
    int lastIndex;
}MaxHeap;

MaxHeap *root = NULL;

void createMaxHeap( int capacity ){
    root = (MaxHeap *)malloc(sizeof(MaxHeap));
    root->capacity = capacity;
    root->lastIndex = -1;
    root->arr = (int *)calloc(capacity,sizeof(int));
}

void swap(int i, int j){
    int temp = root->arr[i];
    root->arr[i] = root->arr[j];
    root->arr[j] = temp;
}

int parent(int i){
    return ((i-1)/2);
}

int leftChild(int i){
    return ((2*i)+1);
}

int rightChild(int i){
    return ((2*i)+2);
}

void insertValue(int value){

    if( root->lastIndex == root->capacity -1 ){
        printf("Heap is Full\n");
        return ;
    }

    root->lastIndex++;
    root->arr[root->lastIndex] = value;
    int index = root->lastIndex;

    while( index!=0 && root->arr[parent(index)] < root->arr[index] ){
        swap(index, parent(index));
        index = parent(index);
    }
}

void balance(int *a,int n,int i){
    int temp = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if(left <= n && root->arr[left] > root->arr[temp]){
        temp = left;
    }
    if(right <= n && root->arr[right] > root->arr[temp]){
        temp = right;
    }

    if(temp != i){
        swap(temp,i);
        balance(a,n,temp);
    }

}


void deleteValue(){
    root->arr[0] = root->arr[root->lastIndex];
    root->arr[root->lastIndex] = 0;
    root->lastIndex--;

    balance(root->arr,root->lastIndex,0);
}

void deleteBetween(int index){
    //when index is given
    root->arr[index] = INT_MAX;
    
    //When Value to be deleted is given
    // int i=0;
    // for(i = 0; i <=root->lastIndex ; i++){
    //     if(root->arr[i] == value){
    //         root->arr[i] = INT_MAX;
    //     }
    // }


    balance(root->arr,root->lastIndex,0);

    deleteValue();
}


void display(){
    int i =0;
    printf("\nMax Heap Implementation\n");
    for( i=0 ; i<= root->capacity ; i++ ){
        printf("%d  ",root->arr[i]);
    }
    printf("\n");
}

int main(){
    createMaxHeap(10);

    insertValue(120);
    insertValue(23);
    insertValue(9);
    insertValue(98);
    insertValue(12);
    display();

    deleteBetween(98);

    display();


    return 0;
}