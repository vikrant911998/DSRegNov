//Max Heap Implementation
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

        void deleteValue(){
            arr[0] = arr[heap_size];
            arr[heap_size] = 0;
            heap_size--;
            int temp = 0;

            int left = leftChild(temp);
            int right = rightChild(temp);
            
            while( left <= heap_size  && right <= heap_size ){
                if( arr[left] > arr[right]){
                    swap( temp, left );
                    temp = left;
                }
                else if(arr[right] > arr[left]){
                    swap( temp, right );
                    temp = right;
                }

                left = leftChild(temp);
                right = rightChild(temp);
            }
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