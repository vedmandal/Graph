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





int main(){

    int v,e;
    cout<<"Enter vertex and edge"<<endl;
    cin>>v>>e;

    vector<vector<Edge>>arr(v);

    cout<<"Enter edges (src,nbr,w) array"<<endl;

    for(int i=0;i<e;i++){
        int src,nbr,w;
        cout<<"Enter src nbr w"<<endl;
        cin>>src>>nbr>>w;
        arr[src].push_back({src,nbr,w});
        arr[nbr].push_back({nbr,src,w});

    }
    vector<bool>visited(v,false);
    int source=0;
    int destination=6;

    cout<<haspath(source,destination,arr,visited);

    for(int i=0;i<v;i++){
        cout<<i<<'->';
        for(auto v:arr[i]){
            cout<<v.src<<","<<v.nbr<<","<<v.w<<endl;
        }
    }



}