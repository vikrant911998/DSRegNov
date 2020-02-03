#include<iostream>
using namespace std;

int main(){
    int arr[10] = {17, 5, -8, -39, 16, -7, 3, 4, 2, 50};
    int num = 0;

    cout<<"Enter the Number "<<endl;
    cin>>num;

    sort(arr,arr+10);

    for( int item : arr ){
        cout<<item<<" ";
    }

    cout<<endl;

    cout<<num<<"th Smallest number is "<< arr[num-1]<<endl;

    return 0;
}
