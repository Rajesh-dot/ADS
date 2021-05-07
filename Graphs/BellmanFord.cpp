#include<bits/stdc++.h>
#include<vector>
#include<map>
using namespace std;


void print(map<int , vector< pair<int, int > > > adjList){
    for(map<int , vector< pair<int, int > > >::iterator it = adjList.begin() ; it != adjList.end() ; it++){
        cout << it->first << " : ";
        vector<pair<int, int> > neighbours = it->second;
        for(int i = 0 ; i < neighbours.size() ; i++){
          cout << "(" << neighbours[i].first << " " << neighbours[i].second << ")";
        }
        cout << endl;
    }
}

map<int,int> bellmen_ford(map<int,vector<pair<int,int> > > graph,int x,int n,vector<int> vertices){
    map<int,int> d;
    int b,w;
    for(int i=1;i<n+1;i++){
        d[vertices[i-1]]=10000;
    }
    d[x]=0;
    for(map<int , vector< pair<int, int > > >::iterator it = graph.begin() ; it != graph.end() ; it++){
        int id=it->first;
        vector<pair<int, int> > neighbours = it->second;
        for(int i = 0 ; i < neighbours.size() ; i++){
            b=neighbours[i].first;
            w=neighbours[i].second;
            d[b]=min(d[id]+w,d[b]);
        }
    }
    return d;
}



int main()
{
    map<int,vector<pair<int,int> > > graph;
    vector<int> vertices;
    int n,vertex,starting,ending,weight,m;


    cout<<"Enter no of vertices: "<<endl;
    cin>>n;


    //cout<<"Enter vertices: "<<endl;
    for(int i=0;i<n;i++){
        //cin>>vertex;
        vertices.push_back(i+1);
    }


    cout<<"Enter no of edges: "<<endl;
    cin>>m;
    cout<<"Enter edges: "<<endl;

    for(int i=0;i<m;i++){
        cin>>starting>>ending>>weight;
        graph[starting].push_back(make_pair(ending,weight));
        graph[ending].push_back(make_pair(starting,weight));
    }


    cout<<"Graph:"<<endl;
    print(graph);


    map<int,int> d = bellmen_ford(graph,1,n,vertices);

    cout<<"Distances from "<<1<<" are:"<<endl;

    for(map<int,int>::iterator it = d.begin() ; it != d.end() ; it++){
        cout<<it->first<<":"<<it->second<<", ";
    }


    cout<<endl;
    return 0;
}

/*
Sample input:
5
7
1 2 5
2 5 2
2 4 3
1 4 7
3 4 1
1 3 3
4 5 2

Graph:
1----2
|\   |\
| \  | 5
|  \ |/
3----4
*/
