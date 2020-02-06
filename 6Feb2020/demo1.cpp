//Malloc( Dynamic Variable Creation)

#include<iostream>
using namespace std;

int main(){
    int a = 2;
    int *ptr = &a;

    cout<<ptr<<endl;
    cout<<*ptr<<endl;

    // int *p = (int *)malloc(4);
    int *p = (int *)malloc( sizeof(int) );
    *p = 100;

    cout<<p<<endl;
    cout<<*p<<endl;

    return 0;
}