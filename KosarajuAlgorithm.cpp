#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Edge{
    public:
    int src;
    int nbr;
    Edge(int src,int nbr){
        this->src=src;
        this->nbr=nbr;
    }
};
void dfs2(vector<vector<Edge>>&newgraph,int src,vector<bool>&newvis){
  newvis[src]=true;

   for(auto edge:newgraph[src]){
    if(newvis[edge.nbr]==false){
        dfs2(newgraph,edge.nbr,newvis);
    }
   }

}
 void dfs(vector<vector<Edge>>&graph,int src,vector<bool>&vis,stack<int>&st){
    vis[src]=true;

    for(auto edge:graph[src]){
        if(vis[edge.nbr]==false){
            dfs(graph,edge.nbr,vis,st);
        }

    }
    st.push(src);

 }


int main(){
    int v,e;
    cout<<"Enter vertex and edge"<<endl;
    cin>>v>>e;

    vector<vector<Edge>>graph(v);
    

    cout<<"Enter edge array"<<endl;
    for(int i=0;i<e;i++){
        int src,nbr;
        cout<<"Enter src and nbr"<<endl;
        cin>>src>>nbr;
        graph[src].push_back({src,nbr});

    }


   vector<bool>vis(v,false);
   stack<int>st;

    for(int i=0;i<v;i++){
        if(vis[i]==false){
             dfs(graph,i,vis ,st);

        }
       
    }

    vector<vector<Edge>>newgraph(v);

   for(int i=0;i<v;i++){
    for(auto edge:graph[i]){
        newgraph[edge.nbr].push_back({edge.nbr,edge.src});
    }
   }

    vector<bool>newvis(v,false);
    int ans=0;
    while(!st.empty()){
        int val=st.top();
        st.pop();
        if(newvis[val]==false){
            dfs2(newgraph,val,newvis);
            ans++;
        }
    }
    cout<<ans<<endl;
}
