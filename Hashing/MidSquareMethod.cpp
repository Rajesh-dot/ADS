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
	    // Mid square method

	    int find_len(int x){
	        int c=0;
	        if(x==0){
                c=1;
	        }
	        while(x!=0){
                x=x/10;
                c+=1;
	        }
	        return c;
	    }

	    int find_mid(int x){
	        int t=find_len(x);
	        if(t%2==1){
                t=t/2;
                int c=0;
                while(x!=0){
                    if(c==t){
                        return x%10;
                    }
                    x=x/10;
                    c+=1;
                }
	        }
	        else{
                t=t/2;
                int c=0;
                while(x!=0){
                    if(c==t-1){
                        int ans=x%10;
                        x=x/10;
                        ans=ans+(x%10)*10;
                        return ans;
                    }
                    x=x/10;
                    c+=1;
                }
	        }
	        return 0;
	    }

	    int f(int x){
	        int square=x*x;
	        int t=find_mid(square);
			return t%size;
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
