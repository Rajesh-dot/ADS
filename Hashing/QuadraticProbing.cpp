#include<iostream>
#include <cstddef>
#include <stdlib.h>
using namespace std;

class Quadratic{
	private:
		int *h;
		int size;
	public:
		Quadratic(int size)
	    {
	        this->size = size;
	        h = (int *)calloc(size, sizeof(int));
	    }
	    int f(int x){
			return x%size;
		}

		void add(int key){
	        int i = f(key);
	        for(int j=0;j<size;j++){
	            int k = (i+j*j) % size;
	            if(h[k]==0){
	                h[k] = key;
	                break;
	            }
	        }
    	}

    	void del(int key){
        	int i = search(key);
        	if(i!=-1)
            	h[i]=0;
        	else
            	cout<<"Element not present in Hash Table, cannot be deleted" << endl;
    	}
    	int search(int key){
	        int i = f(key);
	        for(int j=0;j<size;j++){
	            int k = (i+j*j) % size;
	            if(h[k]==key)
	                return k;
	        }
	        return -1;
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
	Quadratic h(size);
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
				if(h.search(input)!=-1){
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
