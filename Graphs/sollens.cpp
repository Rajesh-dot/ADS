#include<stdio.h>
#include<iostream>
using namespace std;


struct Edge
{
    int src, dest, weight;
};

int find(int parent[],int i){
	if(parent[i]!=i)
        return find(parent,parent[i]);
	return i;
}


void onion(int parent[],int x,int y){
    int x_set_parent = find(parent, x);
    int y_set_parent = find(parent, y);
    parent[y_set_parent] = x_set_parent;
}


int sollens(Edge *edges,int n,int m){
    int parent[n];
    int cheapest[n];
    int ans=0;
    for(int i=0;i<n;i++){
        parent[i]=i;
        cheapest[i]=-1;
    }
    int components = n;
    while(components>1){
        for(int i=0;i<n;i++){
            cheapest[i]=-1;
        }
        for(int i=0;i<m;i++){
            int set1 = find(parent, edges[i].src);
            int set2 = find(parent, edges[i].dest);
            if(set1==set2){
                continue;
            }
            else{
                if(cheapest[set1]==-1 || edges[cheapest[set1]].weight>edges[i].weight){
                    cheapest[set1]=i;
                }
                if(cheapest[set2]==-1 || edges[cheapest[set2]].weight>edges[i].weight){
                    cheapest[set2]=i;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(cheapest[i]!=-1){
                int set1 = find(parent, edges[cheapest[i]].src);
                int set2 = find(parent, edges[cheapest[i]].dest);
                if(set1==set2){
                    continue;
                }
                ans+=edges[cheapest[i]].weight;
                onion(parent,set1,set2);
                components--;
            }
        }
    }
    return ans;
}

int main(){
    int n,vertex,starting,ending,weight,m;

    cout<<"Enter no of vertices: "<<endl;
    cin>>n;

    Edge* edges;

    cout<<"Enter no of edges: "<<endl;
    cin>>m;
    cout<<"Enter edges: "<<endl;

    for(int i=0;i<m;i++){
        cin>>starting>>ending>>weight;
        edges[i].src=starting;
        edges[i].dest=ending;
        edges[i].weight=weight;
    }



    int minimumCost = sollens(edges,n,m);

    cout<<minimumCost;

	return 0;
}

/*
sample input :-
5
7
0 1 5
1 4 2
1 3 3
0 3 7
2 3 1
0 2 3
3 4 2
*/
