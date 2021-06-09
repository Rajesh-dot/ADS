#include<iostream>
#include <stdlib.h>
#include<map>
#include<list>
using namespace std;

int main(){
    int n,r,t;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int, int> rep = {{1,2},{2,1},{3,2},{4,2},{5,2},{6,1},{7,2},{8,2},{9,2},{10,1},{20,1},{30,1},{40,1},{50,1},{60,1},{70,2},{80,2},{90,2},{100,2},{11,3},{12,2},{13,3},{14,4},{15,3},{16,3},{17,4},{18,4},{19,4}};
    int c=0;
    for(int i=0;i<n;i++){
        if(rep.find(a[i])!=rep.end()){
            c+=rep[a[i]];
        }
        else{
            r=a[i]%10;
            c+=rep[r];
            t=a[i]-r;
            c+=rep[t];
        }
    }
    int out=0;
    map<int,int> d;
    for(int i=0;i<n;i++){
        if(d.find(c-a[i])!=d.end() && d[c-a[i]]>0){
            out+=1;
            d[c-a[i]]-=1;
        }
        else{
            if(d.find(a[i])!=d.end()){
                d[a[i]]+=1;
            }
            else{
                d[a[i]]=1;
            }
        }
    }
    cout<<out;

    return 0;
}
