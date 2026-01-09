#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
    int src, nbr;
    Edge(int src, int nbr) {
        this->src = src;
        this->nbr = nbr;
    }
};

void dfs(vector<vector<Edge>>& graph, int src, vector<int>& parent,
         vector<int>& discovery, vector<int>& lowest, vector<bool>& vis,
         vector<bool>& articulationpoint, int &time) {

    vis[src] = true;
    discovery[src] = lowest[src] = time++;
    int children = 0;

    for(auto edge : graph[src]) {

        if(edge.nbr == parent[src])
            continue;

        if(vis[edge.nbr] == true) {
            lowest[src] = min(lowest[src], discovery[edge.nbr]);
        }
        else {
            parent[edge.nbr] = src;
            children++;

            dfs(graph, edge.nbr, parent, discovery, lowest,
                vis, articulationpoint, time);

            lowest[src] = min(lowest[src], lowest[edge.nbr]);

            // Root case
            if(parent[src] == -1 && children > 1) {
                articulationpoint[src] = true;
            }

            // Non-root case
            if(parent[src] != -1 && lowest[edge.nbr] >= discovery[src]) {
                articulationpoint[src] = true;
            }
        }
    }
}

int main() {

    int vtces;
    cin >> vtces;

    vector<vector<Edge>> graph(vtces);

    int edges;
    cin >> edges;

    for(int i = 0; i < edges; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        graph[u].push_back(Edge(u, v));
        graph[v].push_back(Edge(v, u));
    }

    vector<int> parent(vtces, -1);
    vector<int> discovery(vtces, 0);
    vector<int> lowest(vtces, 0);
    vector<bool> vis(vtces, false);
    vector<bool> articulationpoint(vtces, false);

    int time = 0;

    // Run DFS for each component (IMPORTANT)
    for(int i = 0; i < vtces; i++) {
        if(!vis[i]) {
            parent[i] = -1;
            dfs(graph, i, parent, discovery, lowest, vis, articulationpoint, time);
        }
    }

    // Output articulation points
    for(int i = 0; i < vtces; i++) {
        if(articulationpoint[i]) {
            cout << i << " ";
        }
    }
}
