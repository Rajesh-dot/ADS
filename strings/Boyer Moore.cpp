#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
using namespace std;


void badmatch(string ptr,int* t){
    int n=ptr.length();
    for(int i=0;i<256;i++){
        t[i]=n;
    }
    for(int i=0;i<n;i++){
        t[(int)ptr[i]]=n-i-1;
    }
    t[(int)ptr[n-1]]=n;
}

int boyermoore(string str,string ptr){
    int n=str.length();
    int m=ptr.length();
    int t[256];
    badmatch(ptr,t);
    int s=0;
    while(s<=(n-m)){
        int j=m-1;
        while(j>=0 && ptr[j]==str[s+j]){
            j--;
        }
        if(j<0){
            return s;
        }
        else{
            s+=t[(int)str[s+j]];
        }
    }
    return -1;
}

int main(){

	string str,ptr;
	cin>>str;
	cin>>ptr;
	int ans=boyermoore(str,ptr);
	cout<<ans;

	return 0;
}

