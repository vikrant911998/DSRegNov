#include<iostream>
using namespace std;

int main(){
    int arr[8] = {5,1,4,2,2,1,5,0};
    int num = 0;

    cout<<"Enter the Number "<<endl;
    cin>>num;

    sort(arr,arr+8);

    cout<<"Array With Duplicates"<<endl;
    for( int item : arr ){
        cout<<item<<" ";
    }
    int j=0;

    for(int i=0;i<7;i++){
        if( arr[i] != arr[i+1] ){
            arr[j++] = arr[i];
        }
    }

    arr[j++] = arr[7];




    cout<<"Array Without Duplicates"<<endl;
    for( int i=0;i<j;i++){
        cout<<arr[i]<<" ";
    }



    cout<<endl;

    cout<<num<<"th Smallest number is "<< arr[num-1]<<endl;

    return 0;
}
