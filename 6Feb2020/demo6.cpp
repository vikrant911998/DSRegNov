#include<iostream>
using namespace std;

class Demo{
    int id;
    public:
        Demo(int id){
            this->id = id;
        }

        void show(){
            cout<<this->id<<endl;
        }
};

int main(){

    Demo obj(12); //Static Memory Allocation(SMA)
    obj.show();

    Demo *ptr = new Demo(1334); //DMA(Dynamic Memory Allocation)
    ptr->show();



    return 0;
}