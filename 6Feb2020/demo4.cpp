//new (Array Dynamic variable creation)
#include<iostream>
using namespace std;

int main(){

    int *ptr = new int[4];

    for(int i=0;i<4;i++){
        *(ptr+i) = (i+1)*100;
    }

    for(int i=0;i<4;i++){
        cout<<*(ptr+i)<<endl;
    }

    return 0;
}