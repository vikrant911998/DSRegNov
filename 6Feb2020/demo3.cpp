//calloc(multiple variable dynamic creation)
#include<iostream>
using namespace std;

int main(){
    // cout<<sizeof(int)<<endl;
    int num;
    cout<<"Enter the Number of Blocks to be created"<<endl;
    cin>>num;

    int *ptr = (int *)calloc(num,sizeof(int));

    // *(ptr+0) = 100;
    // *(ptr+1) = 200;
    // *(ptr+2) = 300;
    // *(ptr+3) = 400;
    // *(ptr+4) = 500;

    for(int i=0;i<num;i++){
        *(ptr+i) = i*100;
    }

    for(int i=0;i<num;i++){
        cout<<*(ptr+i)<<endl;
    }

    // cout<<(ptr+0)<<endl;
    // cout<<(ptr+1)<<endl;
    // cout<<(ptr+2)<<endl;
    // cout<<(ptr+3)<<endl;
    // cout<<(ptr+4)<<endl;


    return 0;
}