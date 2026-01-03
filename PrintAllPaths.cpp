#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Edge{
    public:

    int src;
    int nbr;
    int w;

    Edge(int src,int nbr,int w){
        this->src=src;
        this->nbr=nbr;
        this->w=w;

    }
};

void PrintAllPaths(vector<vector<Edge>>&graph,vector<bool>&v,int src,int des,string path){
    if(src==des){
        cout<<path<<endl;
        return;
    }
    v[src]=true;
    for(auto edge:graph[src]){
        if(v[edge.nbr]==false){
            PrintAllPaths(graph,v,edge.nbr,des,path+to_string(edge.nbr));
        }
    }

    v[src]=false;

}

int main(){
int v,e;
cout<<"Enter vertex and edges"<<endl;
cin>>v>>e;

  vector<vector<Edge>>graph(v);


  cout<<"Enter Eges(src nbr w) array"<<endl;

  for(int i=0;i<e;i++){
    int src,nbr,w;
    cout<<"Enter src,nbr,w"<<endl;
    cin>>src>>nbr>>w;
    graph[src].push_back({src,nbr,w});
    graph[nbr].push_back({nbr,src,w});

  }

  vector<bool>visted(v,false);

  PrintAllPaths(graph,visted,0,6,to_string(0)+" ");


}