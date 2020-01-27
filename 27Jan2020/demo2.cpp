//Stack Implementation using two queues.

#include<iostream>
#include<queue>
using namespace std;


class Stack{
        queue<int> q1,q2;
    public:

        void push(int data){

            //enqueue value to q2
            q2.push(data);

            //enqueue everything fron q1 to q2
            while(q1.empty() == false){
                q2.push( q1.front() );
                q1.pop();
            }

            //swap the name of q1 and q2
            queue<int> q = q1;
            q1 = q2;
            q2 = q;

        }

        int pop(){
            if(q1.empty()){
                cout<<"Stack Underflow"<<endl;
                exit(0);
            }

            int temp = q1.front();
            q1.pop();
            return temp;
        }

};

int main(){

    Stack s;
    
    s.push(12);
    s.push(57);
    s.push(45);
    s.push(39);

    for(int i=1;i<=4;i++){
        cout<<s.pop()<<endl;
    }

    return 0;
}