#include<iostream>
#include <stdlib.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        int height;
        Node(int data){
            this->data=data;
            left=right=NULL;
            height=1;
        }
};

class AVL{
    public:
        Node * insert(Node *root,int x){
            Node *n=new Node(x);
            if(root==NULL){
                root=n;
                return root;
            }
            else if(root->data>x){
                root->left=insert(root->left,x);
            }
            else{
                root->right=insert(root->right,x);
            }
            root->height = 1+max(height(root->left),height(root->right));
            int bf = balanceFactor(root);
            if(bf>1 && x<root->left->data){
                return right_rotate(root);
            }
            if(bf<-1 && x>root->right->data){
                return left_rotate(root);
            }
            if(bf>1 && x>root->left->data){
                root->left = left_rotate(root->left);
                return right_rotate(root);
            }
            if(bf<-1 && x<root->right->data){
                root->right = right_rotate(root->right);
                return left_rotate(root);
            }
            return root;

        }
        Node * left_rotate(Node *root){
            Node *right=root->right;
            Node *child = right->left;
            right->left = root;
            root->right = child;
            right->height = 1+max(height(right->left),height(right->right));
            root->height = 1+max(height(root->left),height(root->right));
            return right;
        }
        Node * right_rotate(Node *root){
            Node *left = root->left;
            Node *child = left->right;
            left->right = root;
            root->left=child;
            root->height = 1+max(height(root->left),height(root->right));
            left->height = 1+max(height(left->left),height(left->right));
            return left;
        }
        int height(Node *root){
            if(root==NULL){
                return 0;
            }
            else{
                return root->height;
            }
        }
        int balanceFactor(Node *root){
            if(root==NULL){
                return 0;
            }
            return height(root->left)-height(root->right);
        }
        void inorder(Node *root){
            if(root!=NULL){
                inorder(root->left);
                cout<<root->data<<" ";
                inorder(root->right);
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
        Node * del(Node *root,int x){
            if(root==NULL){
                return root;
            }
            if(x<root->data){
                root->left = del(root->left,x);
                root->height = 1+max(height(root->left),height(root->right));
                int bf = balanceFactor(root);
                if(bf>1 && x<root->left->data){
                    return right_rotate(root);
                }
                if(bf<-1 && x>root->right->data){
                    return left_rotate(root);
                }
                if(bf>1 && x>root->left->data){
                    root->left = left_rotate(root->left);
                    return right_rotate(root);
                }
                if(bf<-1 && x<root->right->data){
                    root->right = right_rotate(root->right);
                    return left_rotate(root);
                }
            }
            else if(x>root->data){
                root->right = del(root->right,x);
                root->height = 1+max(height(root->left),height(root->right));
                int bf = balanceFactor(root);
                if(bf>1 && x<root->left->data){
                    return right_rotate(root);
                }
                if(bf<-1 && x>root->right->data){
                    return left_rotate(root);
                }
                if(bf>1 && x>root->left->data){
                    root->left = left_rotate(root->left);
                    return right_rotate(root);
                }
                if(bf<-1 && x<root->right->data){
                    root->right = right_rotate(root->right);
                    return left_rotate(root);
                }
            }
            else{
                if(root->right==NULL && root->left==NULL){
                    root=NULL;
                    return root;
                }
                if(root->left!=NULL && root->right!=NULL){
                    int temp = find_min(root->right);
                    root->data = temp;
                    root->right = del(root->right,temp);
                }
                else if(root->left==NULL){
                    root->data=root->right->data;
                    root->right=del(root->right,root->right->data);
                }
                else{
                    root->data=root->left->data;
                    root->left=del(root->left,root->left->data);
                }
                return root;
            }
            return root;
        }
        int find_min(Node *root){
            if(root==NULL){
                return 0;
            }
            while(root->left!=NULL){
                root=root->left;
            }
            return root->data;
        }
};

int main(){
    AVL t;
    root = t.insert(root, 10);
    root = t.insert(root, 20);
    root = t.insert(root, 30);
    root = t.insert(root, 8);
    root = t.insert(root, 4);
    root = t.insert(root, 40);
    root = t.insert(root, 35);
    root = t.insert(root, 17);
    root = t.insert(root, -1);

    cout << "InOrder: ";
    t.inorder(root);
    cout << endl;

    root = t.del(root,40);
    root = t.del(root,20);
    root = t.del(root,-1);
    root = t.del(root,4);

    cout << "InOrder: ";
    t.inorder(root);
    cout << endl;

    return 0;
}

