#include<iostream>
using namespace std;

int main(){
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 12;

    cout<<ptr<<endl;
    cout<<*ptr<<endl;

    double *p = (double *)realloc(ptr,sizeof(double));

    *p = 200;

    cout<<p<<endl;
    cout<<*p<<endl;

    // free(p);

    // cout<<p<<endl;
    // cout<<*p<<endl;

    return 0;
}