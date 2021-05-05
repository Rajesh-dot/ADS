#include<iostream>
#include <cstddef>
#include <stdlib.h>
using namespace std;

class binaryheap{
	public:
		void heapsort(int a[],int n){
			int temp;
			for(int i=n/2;i>0;i--){
				buildheap(a,n,i);
			}
			for(int i=n-1;i>=1;i--){
				temp=a[1];
				a[1]=a[i];
				a[i]=temp;
				buildheap(a,i-1,1);
			}
		}
		void buildheap(int a[],int n,int i){
			int large=i;
			int l=2*i+1;
			int r=2*i;
			int temp;
			if (l<n && a[l]>a[large]){
				large=l;
			}
			if (r<n && a[r]>a[large]){
				large=r;
			}
			if (large!=i) {
			    temp=a[i];
			    a[i]=a[large];
			    a[large]=temp;
			    buildheap(a,n,large);
			}
		}
		void display(int a[],int n){
			for(int i=0;i<n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
};

int main()
{
    int a[7]={0,33,66,22,88,55,44};
    binaryheap b;
    b.heapsort(a,7);
    for(int i=1;i<7;i++)
      cout<<a[i]<<" ";

    return 0;
}
