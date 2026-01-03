#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
    int src;
    int nbr;
    int w;

    Edge(int src, int nbr, int w) {
        this->src = src;
        this->nbr = nbr;
        this->w = w;
    }
};

void adjacency_list_with_usingList() {
    int v, e;
    cout << "Enter vertices and edges: ";
    cin >> v >> e;

    
    vector<vector<Edge>> adj(v);

    cout << "Enter edges (src nbr weight):" << endl;

    for(int i = 0; i < e; i++) {
        int src, nbr, w;
        cin >> src >> nbr >> w;

       
        adj[src].push_back(Edge(src, nbr, w));
        adj[nbr].push_back(Edge(nbr, src, w));
    }

    cout << "Adjacency List:" << endl;

    for(int i = 0; i < v; i++) {
        cout << i << " -> ";
        for(auto edge : adj[i]) {
            cout << "(" 
                 << edge.src << "," 
                 << edge.nbr << "," 
                 << edge.w << ") ";
        }
        cout << endl;
    }
}

int main() {
    adjacency_list_with_usingList();
   
}
