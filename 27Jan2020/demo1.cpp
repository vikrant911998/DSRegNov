//Queue Implementation using two stacks

#include<iostream>
#include<stack>
using namespace std;

class Queue{

        stack<int> s1,s2;
        
    public:

        void enqueue(int data){

            //push everything from stack1 to stack2
            while( s1.empty() == false){
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }

            //push value into stack1
            s1.push(data);

            //push back everything from stack2 to stack1 
            while(s2.empty() == false){
                s1.push( s2.top());
                s2.pop();
            }
        }

        int dequeue(){
            if(s1.empty()){
                cout<<"Queue is Empty"<<endl;
                exit(0);
            }

            int temp = s1.top();
            s1.pop();

            return temp;
        }

};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    for(int i=1;i<=4;i++){
        cout<<q.dequeue()<<endl;
    }

    return 0;
}