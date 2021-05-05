#include<iostream>
#include <cstddef>
#include <stdlib.h>
using namespace std;

class Node{
    public:
        int data;
        Node *prev;
        Node *next;
        Node(int data){
            this->data=data;
            prev=next=NULL;
        }
};

class Dll{
    private:
        Node *tail;
        Node *head;
        int size;
    public:
        Dll(){
            size=0;
            tail=head=NULL;
        }
        void add(int data){
            Node *n = new Node(data);
            if(head==NULL){
                head=tail=n;
            }
            else{
                tail->next=n;
                n->prev=tail;
                tail=n;
            }
            size++;
        }
        Node* search(int data){
            Node *temp=head;
            while(temp!=NULL){
                if(temp->data==data){
                    return temp;
                }
                temp=temp->next;
            }
            return NULL;
        }
        void del(int data){
            Node *temp=search(data);
            if(temp!=NULL){
                Node *prev=temp->prev;
                Node *next=temp->next;
                if(next!=NULL){
                    next->prev=prev;
                }
                else{
                    tail=prev;
                }
                if(prev!=NULL){
                    prev->next=next;
                }
                else{
                    head=next;
                }
                //free(temp);
                size--;
            }
        }
        void display(){
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout <<"NULL"<<endl;
        }
};

class SPChain{
    private:
        int size;
        Dll *l;
    public:
        SPChain(int size=7){
            this->size=size;
            l = (Dll *)calloc(size,sizeof(Dll));
        }
        int f(int data){
            return data%size;
        }
        void display(){
            for(int i=0;i<size;i++){
                cout<<i<<" - ";
                l[i].display();
            }
        }
        void add(int data){
            l[f(data)].add(data);
        }
        void del(int data){
            l[f(data)].del(data);
        }
        bool search(int data){
            if(l[f(data)].search(data)!=NULL){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){
	int size;
	cout<<"Enter size: "<<endl;
	cin>>size;
	int input,choice,id;
	SPChain h(size);
	while(true){
		cout<<"Enter choice"<<endl;
		cout<<"1.) insert\n2.) delete\n3.) search\n4.) quit\n";
		cin>> choice;
		switch(choice){
			case 1:
				cout<<"Enter input: ";
				cin>>input;
				h.add(input);
				h.display();
				break;
			case 2:
				cout<<"Enter input: ";
				cin>>input;
				h.del(input);
				h.display();
				break;
			case 3:
				cout<<"Enter input: ";
				cin>>input;
				if(h.search(input)){
					cout<<"Found"<<endl;
				}
				else{
					cout<<"Not Found"<<endl;
				}
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"Wrong choice"<<endl;
				break;
		}
	}
    return 0;
}
