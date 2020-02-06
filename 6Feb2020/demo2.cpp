//new (Dynamic Variable Creation in CPP)

#include<iostream>
using namespace std;

int main(){
    int *ptr = new int;
    *ptr = 200;

    cout<<ptr<<endl;
    cout<<*ptr<<endl;


    string *str;
    str = new string;

    *str = "Vikrant";

    cout<<str<<endl;
    cout<<*str<<endl;

    return 0;
}