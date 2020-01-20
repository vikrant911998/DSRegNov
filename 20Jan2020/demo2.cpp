//Iterative PostOrder Traversal

#include<iostream>
#include<stack>
using namespace std;

class Node{
    
    public:
        int data;
        Node *left,*right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BST{
        Node *root;
        

    public:
        BST(){
            root = NULL;
        }

        void createBST(int data){
            root = new Node(data);   
        }

        Node *getRoot(){
            return root;
        }

        void insertNode(Node *rootNode, int data){

            Node *newNode = new Node(data);
            
            if(rootNode->right == NULL && data > rootNode->data){
                rootNode->right = newNode;
                return ;
            }

            if(rootNode->left == NULL && data < rootNode->data){
                rootNode->left = newNode;
                return ;
            }

            if( data > rootNode->data){
                insertNode(rootNode->right,data);
            }
            else{
                insertNode(rootNode->left,data);
            }

        }

        void IterativePostorder(Node *rootNode){
            stack<Node *> s1,s2;

            s1.push(rootNode);
            Node *temp;

            while(!s1.empty()){
                temp = s1.top();
                s1.pop();
                s2.push(temp);

                if(temp->left){
                    s1.push(temp->left);
                }
                if(temp->right){
                    s1.push(temp->right);
                }
            }

            while(!s2.empty()){
                temp = s2.top();
                s2.pop();
                printf("%d  ",temp->data);
            }
        }

};



int  main(){

    BST obj;
    obj.createBST(10);
    Node *root = obj.getRoot();
    obj.insertNode(root,20);
    obj.insertNode(root,7);
    obj.insertNode(root,17);
    obj.insertNode(root,16);
    obj.insertNode(root,45);
    obj.insertNode(root,39);

    obj.IterativePostorder(root);

    return 0;
}