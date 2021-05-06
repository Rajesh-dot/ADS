#include<iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data=data;
            left=right=NULL;
        }
};

class BST{
    public:
        Node * insert(Node *root,int x){
            Node *n = new Node(x);
            if(root==NULL){
                root=n;
            }
            else if(root->data>x){
                root->left=insert(root->left,x);
            }
            else{
                root->right=insert(root->right,x);
            }
            return root;
        }
        void inorder(Node *root){
            if(root!=NULL){
                inorder(root->left);
                cout<<root->data<<" ";
                inorder(root->right);
            }
        }
        void preorder(Node *root){
            if(root!=NULL){
                cout<<root->data<<" ";
                preorder(root->left);
                preorder(root->right);
            }
        }
        void postorder(Node *root){
            if(root!=NULL){
                postorder(root->left);
                postorder(root->right);
                cout<<root->data<<" ";
            }
        }
        int height(Node *root){
            if(root==NULL){
                return 0;
            }
            else{
                return max(height(root->left),height(root->right))+1;
            }
        }
        bool search(Node *root,int x){
            if(root==NULL){
                return false;
            }
            else if(root->data==x){
                return true;
            }
            else if(root->data>x){
                return search(root->left,x);
            }
            else{
                return search(root->right,x);
            }
        }
        int get_max(Node *root){
            if(root==NULL){
                return -1;
            }
            else{
                if(root->left==NULL){
                    return root->data;
                }
                else{
                    return get_max(root->left);
                }
            }
        }
        int get_min(Node *root){
            if(root==NULL){
                return -1;
            }
            else{
                if(root->right==NULL){
                    return root->data;
                }
                else{
                    return get_min(root->right);
                }
            }
        }
        void level_order(Node *root){
            queue<Node *> q;
            q.push(root);
            while(q.size()!=0){
                Node *curr=q.front();
                cout<<curr->data<<" ";
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
                q.pop();
            }
        }
};

int main(){
    BST t;
    Node *root=NULL;
    root = t.insert(root, 15);
    root = t.insert(root, 10);
    root = t.insert(root, 20);
    root = t.insert(root, 25);
    root = t.insert(root, 8);
    root = t.insert(root, 12);
    int number;
    cout<<"Enter number to search: "<<endl;
    cin >> number;
    if (t.search(root, number)) cout << "Found\n";
    else cout << "Not Found\n";

    cout << "Min = "<<t.get_min(root) << endl;
    cout << "Max = "<<t.get_max(root) << endl;

    cout << "Level order: ";
    t.level_order(root);
    cout << endl;

    cout << "PreOrder: ";
    t.preorder(root);
    cout << endl;

    cout << "InOrder: ";
    t.inorder(root);
    cout << endl;

    cout << "PostOrder: ";
    t.postorder(root);
    cout << endl;
    return 0;
}

