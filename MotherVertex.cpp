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

void dfs(vector<vector<Edge>>&graph,int src,vector<bool>&vis,stack<int>&st){
    vis[src]=true;
    for(auto edge:graph[src]){
        if(vis[edge.nbr]==false){
            dfs(graph,edge.nbr,vis,st);
        }
    }
    st.push(src);
}
void dfs2(vector<vector<Edge>>&graph,int src,int &c,vector<bool>&newvis){
    newvis[src]=true;
    c++;
    for(auto edge:graph[src]){
        if(newvis[edge.nbr]==false){
            dfs2(graph,edge.nbr,c,newvis);
        }
    }
    
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

    stack<int>st;
    vector<bool>vis(v,false);

    for(int i=0;i<v;i++){
        if(vis[i]==false){
             dfs(graph,i,vis,st);

        }
       
    }

    int ans=st.top();

    vector<bool>newvis(v,false);
    int c=0;
    dfs2(graph,ans,c,newvis);
   
    if(c==v){
        cout<<ans;
    }else{
        cout<<" -1";
    }


}