#include<iostream>
#include<vector>
#include<stack>

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

bool haspath(int src,int des,vector<vector<Edge>>&arr,vector<bool>&v){
    if(src==des){
        return true;
    }
    v[src]=true;
    for(Edge edge:arr[src]){
        if(v[edge.nbr]==false){
             if(haspath(edge.nbr,des,arr,v)==true){
                return true;
             }

        }
       

    }
    return false;


}


 void topologicalSort(vector<vector<Edge>>&graph,vector<bool>&vis,int src,stack<int>&st){
     
     
     vis[src]=true;
     for(auto edge:graph[src]){
        if(vis[edge.nbr]==false){
            topologicalSort(graph,vis,edge.nbr,st);
        }
     }
     st.push(src);
 }


int main(){

    int v,e;
    cout<<"Enter vertex and edge"<<endl;
    cin>>v>>e;

    vector<vector<Edge>>graph(v);

    cout<<"Enter edges (src,nbr,w) array"<<endl;

    for(int i=0;i<e;i++){
        int src,nbr,w;
        cout<<"Enter src nbr w"<<endl;
        cin>>src>>nbr>>w;
        graph[src].push_back({src,nbr,w});
       

    }
    vector<bool>vis(v,false);
    stack<int>st;
   
     for(int i=0;i<v;i++){
        if(vis[i]==false){
            topologicalSort(graph,vis,i,st);
        }
     }

     while (!st.empty())
     {
       cout<<st.top()<<" ";
       st.pop();
     }
     
   



}