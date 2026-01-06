#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Edge{
    public:
    int v;
    int wt;
    Edge(int v,int wt)
    {
        this->v=v;
        this->wt=wt;
    }
};

class comp{
  public:
    bool operator () (Edge a,Edge b)
    {
        return a.wt>b.wt;
    }
};

int main()
{
    int vtces;
    cin>>vtces;
    vector<vector<Edge>> graph(vtces);
    int edges;cin>>edges;
    for(int i=0;i<edges;++i)
    {
        int v1;cin>>v1;
        int v2;cin>>v2;
        int wt;cin>>wt;
        graph[v1].push_back(Edge(v2,wt));
        graph[v2].push_back(Edge(v1,wt));
    }
    
    int ans=0;
    priority_queue<Edge,vector<Edge>,comp> pq;
    pq.push(Edge(0,0));
    vector<bool> vis(vtces);
    while(pq.size()>0)
    {
        Edge rem=pq.top();
        pq.pop();
        if(vis[rem.v]) continue;
        ans+=rem.wt;
        vis[rem.v]=true;
        vector<Edge> nbrs=graph[rem.v];
        for(Edge edg:nbrs)
            if(!vis[edg.v]) pq.push(edg);
    }
    cout<<ans<<"\n";

    
    return 0;
}                                
            