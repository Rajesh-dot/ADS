#include<iostream>
#include <stack>
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
        bool search(Node *root,int x){
            if(root==NULL){
                return false;
            }
            Node* curr = root;
            while(curr!=NULL){
                if(curr->data==x){
                    return true;
                }
                if(curr->data<x){
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                }
            }
            return false;
        }
        Node* del(Node* root,int x){
            if(root==NULL){
                return root;
            }
            Node* curr = root;
            Node* prev = NULL;
            while(curr!=NULL){
                if(curr->data==x){
                    if(curr->left==NULL || curr->right==NULL){
                        if(curr->left==NULL){
                            if(prev->left->data==curr->data){
                                prev->left=curr->right;
                            }
                            else{
                                prev->right=curr->right;
                            }
                        }
                        else{
                            if(prev->left->data==curr->data){
                                prev->left=curr->left;
                            }
                            else{
                                prev->right=curr->left;
                            }
                        }
                        free(curr);
                    }
                    else{
                        Node* p = NULL;
                        Node* temp;
                        temp = curr->right;
                        while (temp->left != NULL) {
                            p = temp;
                            temp = temp->left;
                        }
                        if (p != NULL){
                            p->left = temp->right;
                        }
                        else{
                            curr->right = temp->right;
                        }

                        curr->data = temp->data;
                        free(temp);
                    }
                    return root;
                }
                prev = curr;
                if(curr->data<x){
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                }
            }
            cout<<"Element not found"<<endl;
            return root;
        }
        Node* get_min(Node *root){
            Node* curr=root;
            while(curr->left!=NULL){
                curr=curr->left;
            }
            return curr;
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
    cout << "Search: ";
    cout<<t.search(root,5);
    cout << endl;
    root=t.del(root,20);
    cout << "Inorder: ";
    t.inorder(root);
    cout << endl;
    return 0;
}

