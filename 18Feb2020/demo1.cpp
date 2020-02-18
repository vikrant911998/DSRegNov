#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left,*right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right= NULL;
        }
};

class MT{
    
    public:
        Node *root;

        MT(int v1,int v2,int v3,int v4, int v5){
            Node *n1 =  new Node(v1);
            Node *n2 =  new Node(v2);
            Node *n3 =  new Node(v3);
            Node *n4 =  new Node(v4);
            Node *n5 =  new Node(v5);

            root = n1;
            n1->left = n3;
            n1->right = n2;
            n2->left = n5;
            n2->right = n4;
        }

        void mirror_tree(Node *rootNode){ //1,2
            if(rootNode == NULL){
                return ;
            }
            else{
                mirror_tree(rootNode->left); //3,5
                mirror_tree(rootNode->right);//2,4

                Node *temp = rootNode->left;
                rootNode->left = rootNode->right;
                rootNode->right = temp;
            }
        }

        void inorder(Node *rootNode){
            if(rootNode == NULL){
                return;
            }

            inorder(rootNode->left);
            cout<<rootNode->data<<" ";
            inorder(rootNode->right);
        }

};


int main(){
    MT obj(1,2,3,4,5);
    obj.mirror_tree(obj.root);
    obj.inorder(obj.root);



    return 0;
}