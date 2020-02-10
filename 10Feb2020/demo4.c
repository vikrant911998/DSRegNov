//Heap Sort.

#include<stdio.h>
#include<stdlib.h>

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
    int temp = root->arr[0];
    root->arr[0] = root->arr[root->lastIndex];
    root->arr[root->lastIndex] = temp;
    root->lastIndex--;

    balance(root->arr,root->lastIndex,0);
}

void heap_sort(){
    while(root->lastIndex != 0){
        deleteValue();
    }
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

    heap_sort();

    display();


    return 0;
}