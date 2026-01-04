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
        this->w=w;
    }
};

class pairs{
    public:
    int v;
    int wsf;
    string path;
    pairs(int v,int wsf,string path){
        this->v=v;
        this->wsf=wsf;
        this->path=path;
    }

};
struct comp{
    public:
    bool operator()(pairs const &a, pairs const &b)const{
        return a.wsf>b.wsf;

    }
};



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
    vector<bool>vis(v,false);
    priority_queue<pairs,vector<pairs>,comp>q;
    q.push({0,0,to_string(0)+""});

    while(!q.empty()){

        pairs rem=q.top();
        q.pop();

        if(vis[rem.v]==true){
            continue;
        }
        vis[rem.v]=true;

        cout<<rem.v<<"via"<<rem.path<<"@"<<" "<< rem.wsf<<endl;
        for(auto edge:arr[rem.v]){
            if(vis[edge.nbr]==false){
                q.push({edge.nbr,rem.wsf+edge.w,rem.path+to_string(edge.nbr)});
            }

        }

    }
    
   

   



}