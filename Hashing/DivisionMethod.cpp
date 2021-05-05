#include<iostream>
#include <cstddef>
#include <stdlib.h>
using namespace std;
class HashTable{
	private:
		int *h;
		int size;
	public:
		HashTable(int size)
	    {
	        this->size = size;
	        h = (int *)calloc(size, sizeof(int));
	    }
	    int f(int x){
			return x%size;
		}

		void add(int x){
			h[f(x)]=x;
		}

		bool search(int x){
			if(h[f(x)]==x){
				return true;
			}
			return false;
		}


		void del(int x){
			if(search(x)){
				h[f(x)]=0;
			}
		}

		void display(){
			for(int i=0;i<size;i++){
				cout<<"[ "<<i<<" : "<<h[i]<<" ]";
			}
			cout<<endl;
		}
};


int main(){
	int size;
	cout<<"Enter size: "<<endl;
	cin>>size;
	int input,choice,id;
	HashTable h(size);
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
				cout<<"Wrong choce"<<endl;
				break;
		}
	}
	return 0;
}
