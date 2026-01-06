#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Edge {
public:
    int node;
    int cost;

    Edge(int n, int c) {
        node = n;
        cost = c;
    }
};

  // Min-heap comparator
class Compare {
public:
    bool operator()(const Edge &a,const  Edge &b)const {
        return a.cost > b.cost;
    }
};

int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
    vector<vector<Edge>> graph(n + 1);

    // Virtual node 0 -> houses
    for (int i = 1; i <= n; i++) {
        graph[0].push_back(Edge(i, wells[i-1]));
        graph[i].push_back(Edge(0, wells[i-1]));
    }

    // Pipe edges
    for (auto &p : pipes) {
        int u = p[0], v = p[1], c = p[2];
        graph[u].push_back(Edge(v, c));
        graph[v].push_back(Edge(u, c));
    }

    priority_queue<Edge, vector<Edge>, Compare> pq;
    vector<bool> visited(n + 1, false);

    pq.push(Edge(0, 0));
    int totalCost = 0;

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();

        int node = curr.node;
        int cost = curr.cost;

        if (visited[node]) continue;

        visited[node] = true;
        totalCost += cost;

        for (Edge &nbr : graph[node]) {
            if (!visited[nbr.node]) {
                pq.push(nbr);
            }
        }
    }

    return totalCost;
}

   

int main(){
    int v,e;
    cout<<"Enter vertex and edges"<<endl;
    cin>>v>>e;
    vector<int>wells(v);
    cout<<"Enter wells array"<<endl;
    for(int i=0;i<v;i++){
        cin>>wells[i];
    }

    vector<vector<int>>pipes(e,vector<int>(3));

    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>pipes[i][j];
        }
    }

    cout<<minCostToSupplyWater(v,wells,pipes);

}