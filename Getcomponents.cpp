#include<iostream>
#include<vector>
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

void getcomponents(vector<vector<Edge>>&graph,vector<bool>&vis,vector<int>&comp,int src){
    vis[src]=true;
    comp.push_back(src);

    for(auto edge :graph[src]){
        if(vis[edge.nbr]==false){
            getcomponents(graph,vis,comp,edge.nbr);
            
           

        }
    }
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
  
  vector<vector<int>>ans;

vector<bool>visted(v,false);
  for(int i=0;i<v;i++){
    if(visted[i]==false){
        vector<int>comps;
        getcomponents(graph,visted,comps,i);
        ans.push_back(comps);
    }

  }

  cout << "Connected Components:" << endl;
   for(auto comp : ans){
      for(int v : comp){
        cout << v << " ";
      }
    cout << endl;
}


  

}