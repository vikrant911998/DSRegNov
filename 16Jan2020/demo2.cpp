#include<iostream>
using namespace std;


class Node{   
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


class SingleLinkedList{
    public:
        Node *start;
        int length;

        SingleLinkedList(){
            this->start = NULL;
        }

        void createList(){
            Node *temp = NULL;
            int value;

            cout<<"Enter the Value"<<endl;
            cin>>value;


            while(value != -1){
                Node *newNode = new Node(value);

                if(start == NULL){
                    start = newNode;
                    temp = newNode;
                }
                else{
                    temp->next = newNode;
                    temp = newNode;
                }

                cin>>value;
                this->length++;
            }

        }

        int getLength(){
            return length;
        }

        void sumOfLastNnodes(int n){
            int index = length-n;
            int sum=0;
            Node *temp = start;
            int count = 0;

            while(temp != NULL){

                if(count >= index){
                    sum += temp->data;
                }

                temp = temp->next;
                count++;
            }

            cout<<"Sum of Last "<<n<<" Nodes  is "<<sum<<endl;

        }

        void display();
};

void SingleLinkedList::display(){
    Node *temp = start;

    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}



int main(){
    SingleLinkedList object;
    object.createList();
    // object.display();

    int n; // last n nodes.

    cout<<"Enter the value of N"<<endl;
    cin>>n;

    object.sumOfLastNnodes(n);

    

    return 0;
}





