//LevelOrder Traversal

#include<iostream>
#include<queue>
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
        queue<Node *> q;

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


        void levelOrder(Node *rootNode){

            q.push(rootNode);
            
            while(q.empty() == false){
                Node *node = q.front(); 
                cout << node->data << "  "; 
                q.pop(); 
        
            
                if (node->left != NULL) 
                    q.push(node->left); 
        
                
                if (node->right != NULL) 
                    q.push(node->right);
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

    obj.levelOrder(root);

    return 0;
}