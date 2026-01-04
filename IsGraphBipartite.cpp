#include<iostream>
#include<vector>
#include<queue>
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
        this->w;
    }
};

class pairs{

    public:
    int v;
    int l;
    string path;
    pairs(int v,int l,string path){
        this->v=v;
        this->l=l;
        this->path=path;
    }

};

  bool isbipartite(vector<vector<Edge>>&graph,vector<int>&vis,int src){
    queue<pairs>q;
   q.push({src,0,to_string(src)+" "});

   while(!q.empty()){
       pairs rem=q.front();

       q.pop();

       if(vis[rem.v]!=-1 && vis[rem.v]!=rem.l){
        return false;
        

       }else{
          vis[rem.v]=rem.l;

       }

     

       for(auto edge :graph[rem.v]){
        if(vis[edge.nbr]==-1){
            q.push({edge.nbr,rem.l+1,rem.path+to_string(edge.nbr)});
        }
       }
   }

   return true;



  }

int main(){
    int v,e;
    cout<<"Enter verices and edges"<<endl;
    cin>>v>>e;

    vector<vector<Edge>>graph(v);

    cout<<"Enter edges array"<<endl;

    for(int i=0;i<e;i++){
        int src,nbr,w;
        cout<<"Enter src nbr w"<<endl;
        cin>>src>>nbr>>w;

        graph[src].push_back({src,nbr,w});
        graph[nbr].push_back({nbr,src,w});
    }

    vector<int>vis(v,-1);

    for(int i=0;i<v;i++){
        if(vis[i]==-1){
            if(isbipartite(graph,vis,i)==false){
                cout<<"Graph is bipartite"<<endl;
                return;
            }
        }
    }
    cout<<"GRAPH IS NOT BIPARTITE"<<endl;

}