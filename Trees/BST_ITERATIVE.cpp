#include<iostream>
#include <stack>
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


void PrintStack(stack<Node *> s)
{
    if (s.empty())
        return;


    Node * x = s.top();

    s.pop();
    cout << x->data << " ";
    s.push(x);
}

class BST{
    public:
        void insert(Node *&root,int x){
            Node *n = new Node(x);
            Node *curr = root;
            Node *prev=NULL;
            while(curr!=NULL){
                prev = curr;
                if(curr->data>x){
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }
            }
            if(prev==NULL){
                prev = n;
                root = prev;
            }
            else if(prev->data>x){
                prev->left = n;
            }
            else{
                prev->right = n;
            }
        }
        void inorder(Node *root){
            stack<Node *> s;
            Node *t = root;
            while(!s.empty() || t!=NULL){
                if(t!=NULL){
                    s.push(t);
                    t=t->left;
                }
                else{
                    t = s.top();
                    cout<<t->data<<" ";
                    t = t->right;
                    s.pop();
                }
            }
        }
};
int main(){
    BST t;
    Node *root=NULL;
    t.insert(root, 15);
    t.insert(root, 10);
    t.insert(root, 20);
    t.insert(root, 25);
    t.insert(root, 8);
    t.insert(root, 12);

    cout << "Inorder: ";
    t.inorder(root);
    cout << endl;
    return 0;
}

