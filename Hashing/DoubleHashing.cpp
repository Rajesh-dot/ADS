#include<iostream>
#include <stdlib.h>
using namespace std;

class ReHashing{
	private:
		int *h;
		int size;
		int n;
	public:
		ReHashing(int size)
	    {
	        this->size = size;
	        h = (int *)calloc(size, sizeof(int));
	        for(int i=size+1;i<size*size;i++){
	            int c=0;
                for(int j=2;j<i;j++){
                    if(i%j==0){
                        c+=1;
                        break;
                    }
                }
                if(c==0){
                    n=i;
                    break;
                }
	        }
	    }

	    int h2(int x){
	        return n-x%size;
	    }

	    int f(int x){
			return x%size;
		}

		void add(int key){
	        int i = f(key);
	        for(int j=0;j<size;j++){
	            int k = (i+j*h2(key)) % size;
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
	            int k = (i+j*h2(key)) % size;
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
	ReHashing h(size);
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
