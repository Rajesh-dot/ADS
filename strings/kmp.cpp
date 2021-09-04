#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
using namespace std;


void pitable(string str,string ptr,int* pi){
	int pl=0;
	pi[0]=0;
	int i=1;
	int n = ptr.length();
	while (i<n){
		if (ptr[i]==ptr[pl]){
			pi[i]=pl+1;
			pl++;
			i++;
		}
		else{
			if(pl!=0){
				pl=pi[pl-1];
			}
			else{
				pi[i]=0;
				i++;
			}
		}
	}
}


int kmp(string str,string ptr){
	int n = str.length();
	int m = ptr.length();
	int pi[m];
	pitable(str,ptr,pi);
	int i=0;
	int j=0;
	while(i<n){
		if(str[i]==ptr[j]){
			i++;
			j++;
		}
		else{
			if(j==0){
				i++;
			}
			else{
				j=pi[j-1];
			}
		}
		if(j==m){
			return i-j;
		}
	}
	return -1;
}

int main(){

	string str,ptr;
	cin>>str;
	cin>>ptr;
	int ans=kmp(str,ptr);
	cout<<ans;

	return 0;
}


