//Maximum Width of BST

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

        int getWidth(Node *rootNode, int level){
            if(rootNode == NULL){
                return 0;
            }
            if(level == 1){
                return 1;
            }
            else if(level >1){
                return getWidth(rootNode->left,level-1)+getWidth(rootNode->right,level-1);
            }
        }

        int maximumWidth(Node *rootNode){

            int maxWidth = 0;

            for(int i=1;i<=4;i++){
                int width = getWidth(rootNode,i);
                if( width > maxWidth){
                    maxWidth = width;
                }
            }

            return maxWidth;
        }


};



int  main(){

    BST obj;
    obj.createBST(5);
    Node *root = obj.getRoot();
    obj.insertNode(root,3);
    obj.insertNode(root,4);
    obj.insertNode(root,2);
    obj.insertNode(root,6);
    obj.insertNode(root,7);
    obj.insertNode(root,8);

    cout<<"MAX Width = "<<obj.maximumWidth(root);
    cout<<endl;

    return 0;
}