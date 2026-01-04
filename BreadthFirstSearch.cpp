#include<iostream>
#include<vector>
#include<string>
#include<queue>


using namespace std;

class Edge{
    public:

    int src;
    int nbr;
    int w;
    Edge(int src,int nbr, int w){
        this->src=src;
        this->nbr=nbr;
        this->w=w;
    }
};


class pairs{
    public:
    int v;
    string path;
    pairs(int v,string path){
        this->v=v;
        this->path=path;
    }
};



void BreadthFirstSearch(vector<vector<Edge>>&graph,vector<bool>&vis,int src){

    queue<pairs>q;
    q.push({src,to_string(src)+" "});

    while(!q.empty()){

        pairs rem=q.front();
        q.pop();

        if(vis[rem.v]==true){
            continue;
        }
        vis[rem.v]=true;

        cout<<to_string(rem.v)+"@"+rem.path<<endl;
        
        for(auto edge :graph[rem.v]){
            if(vis[edge.nbr]==false){
                q.push({edge.nbr,rem.path + to_string(edge.nbr)});

            }
        }
    }



}



int main(){
    int v,e;
    cout<<"Enter vertices and edge"<<endl;
    cin>>v>>e;

    vector<vector<Edge>>graph(v);
    
   cout<<"Enter edge array"<<endl;
    for(int i=0;i<e;i++){
        int src,nbr,w;
        cout<<"Enter edge (src,nbr,w)"<<endl;
        cin>>src>>nbr>>w;
        graph[src].push_back({src,nbr,w});
        graph[nbr].push_back({nbr,src,w});
    }

    int src;
    cout<<"Enter source"<<endl;
    cin>>src;
     vector<bool>vis(v,false);
    BreadthFirstSearch(graph,vis,src);
}