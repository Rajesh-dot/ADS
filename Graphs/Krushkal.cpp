#include<bits/stdc++.h>
#include<vector>
#include<map>
using namespace std;


struct Data
{
   int start, ending, weight;
};


bool compareData(Data i1, Data i2)
{
    return (i1.weight < i2.weight);
}


int find(int parents[], int vertex){
    if(parents[vertex]!=vertex)
        return find(parents, parents[vertex]);;
    return vertex;
}


void make_union(int parents[], int x, int y){
    int x_set_parent = find(parents, x);
    int y_set_parent = find(parents, y);
    parents[y_set_parent] = x_set_parent;
}


int main()
{
    int n,vertex,starting,ending,weight,m;


    cout<<"Enter no of vertices: "<<endl;
    cin>>n;

    vector<Data> edges;

    cout<<"Enter no of edges - (starting,ending,weight): "<<endl;
    cin>>m;

    cout<<"Enter edges: "<<endl;

    for(int i=0;i<m;i++){
        cin>>starting>>ending>>weight;
        edges.push_back({starting,ending,weight});
    }


    int parents[n+1];
    for (int i=0; i<=n; i++) {
        parents[i] = i;
    }

    sort(edges.begin(), edges.end(), compareData);
    int minimumCost = 0;
    for(Data x:edges){
        int x_set = find(parents, x.start);
        int y_set = find(parents, x.ending);
        if(x_set!=y_set){
            make_union(parents, x_set, y_set);
            minimumCost+=x.weight;
        }
    }
    cout<<"Minimum Cost for spanning Tree is:"<<endl;
    cout<<minimumCost;

    cout<<endl;
    return 0;
}


/*
Sample input:-
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
