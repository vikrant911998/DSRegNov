//Deletion in Max Heap (C++)
#include<iostream>
using namespace std;




class MaxHeap{
    int *arr;
    int heap_size;
    int capacity;
    
    public:
        MaxHeap(int capacity){
            this->capacity = capacity;
            heap_size = -1;
            arr = new int[capacity];
        }

        void swap(int index1, int index2){
            int temp = arr[index1];
            arr[index1] = arr[index2];
            arr[index2] = temp; 
        }

        int parent(int index){
            return ((index-1)/2);
        }
        int leftChild(int index){
            return ((2*index) + 1);
        }
        int rightChild(int index){
            return ((2*index) + 2);
        }

        void insertValue(int value){

            if( heap_size == capacity-1 ){
                cout<<"heap Overflow"<<endl;
            }

            heap_size++; //0
            arr[heap_size] = value;
            int index = heap_size;

            while(index != 0 && arr[parent(index)] < arr[index] ){
                
                swap( parent(index) , index );
                index = parent(index);
            }
        }

        void balance(int *a,int n,int i){
            int temp = i;
            int left = leftChild(i);
            int right = rightChild(i);

            if(left <= heap_size && a[left] > a[temp]){
                temp = left;
            }
            if(right <= heap_size && a[right] > a[temp]){
                temp = right;
            }

            if(temp != i){
                swap(i,temp);

                balance(a,n,temp);
            }
        }

        void deleteValue(){
            arr[0] = arr[heap_size];
            arr[heap_size] = 0;
            heap_size--;
            
            balance(arr,heap_size,0);
        }

        void display(){
            
            for(int i=0 ; i<=heap_size ;i++){
                cout<<arr[i]<< " ";
            }
            cout<<endl;
        }

};


int main(){
    MaxHeap obj(10);

    int value = 0;

    cout<<"Enter the value"<<endl;
    cin>>value;


    while(value != -1){
        
        obj.insertValue(value);

        cin>>value;
    }

    obj.display();

    obj.deleteValue();

    obj.display();

    return 0;
}