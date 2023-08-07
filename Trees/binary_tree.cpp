#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left= nullptr;
        this->right= nullptr;
    }
};

void createBinaryTree(Node* &root){
    int x;
    queue<Node*> q;
    cout<<"Enter root node: "<<endl;
    cin>>x;
    root=new Node(x);
    q.push(root);
    while(!q.empty()){
        Node* p = q.front();
        q.pop();
        //Enter Left Node of parent:
        cout<<"Enter left child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            Node* new_node = new Node(x);
            p->left = new_node;
            q.push(new_node);
        }

        //Enter right Node of parent:
        cout<<"Enter right child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            Node* new_node = new Node(x);
            p->right = new_node;
            q.push(new_node);
        }
    }
}


//RECURSIVE TREE TRAVERSALS:

void preorder_traversal(Node* root){
    if(root== nullptr) return;
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(Node* root){
    if(root== nullptr) return;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

void postorder_traversal(Node* root){
    if(root== nullptr) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
}

void level_order_traversal(Node* root){
     queue<Node*> q;
     cout<<root->data<<" ";
     q.push(root);

     while(!q.empty()){
         Node* p = q.front();
         q.pop();

         if(p->left){
             cout<<p->left->data<<" ";
             q.push(p->left);
         }

         if(p->right){
             cout<<p->right->data<<" ";
             q.push(p->right);
         }
     }
}


//ITERATIVE TREE TRAVERSALS ALSO EXISTS: THEY USE STACKS.


//HEIGHT OF A BINARY TREE: 

int height(Node* p){
    int x, y;
    if(p!= nullptr){
        x= height(p->left);
        y= height(p->right);
        if(x>y) return x+1;
        else return y+1;
    }
    return 0;
}

int count(Node* p){
    int x,y;
    if(p!= nullptr){
        x=count(p->left);
        y=count(p->right);
        return x+y+1;
    }
    return 0;
}
int main(){

    Node* root = nullptr;
    createBinaryTree(root);


    /*   TREE:
     *              5
     *           /    \
     *          8      6
     *          \     /
     *           9   3
     *          / \
     *        4    2
     * * */

    cout<<endl<<endl<<"Pre-Order Traversal: "<<endl;
    preorder_traversal(root);

    cout<<endl<<"InOrder Traversal: "<<endl;
    inorder_traversal(root);

    cout<<endl<<"Post-Order Traversal"<<endl;
    postorder_traversal(root);

    cout<<endl<<"Level-Order Traversal"<<endl;
    level_order_traversal(root);

}