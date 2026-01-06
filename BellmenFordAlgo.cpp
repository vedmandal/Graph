/*
Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

Examples:

Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0

Output: [0, 5, 6, 6, 7]
Explanation: Shortest Paths:
For 0 to 1 minimum distance will be 5. By following path 0 → 1
For 0 to 2 minimum distance will be 6. By following path 0 → 1  → 2
For 0 to 3 minimum distance will be 6. By following path 0 → 1  → 2 → 4 → 3 
For 0 to 4 minimum distance will be 7. By following path 0 → 1  → 2 → 4
Input: V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0

Output: [-1]
Explanation: The graph contains a negative weight cycle formed by the path 1 → 2 → 3 → 1, where the total weight of the cycle is negative.
Constraints:
1 ≤ V ≤ 100
1 ≤ E = edges.size() ≤ V*(V-1)
-1000 ≤ w ≤ 1000
0 ≤ src < V

*/




#include<bits/stdc++.h>
using namespace std;
//ballmon algorithm

int main(){
    
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges(m,vector<int>(3));
    
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        
        edges[i][0]=x-1;
        edges[i][1]=y-1;
        edges[i][2]=z;
        
    }
    
    vector<int> path(n);
    
    for(int i=0;i<n;i++){
        path[i]=INT_MAX;
    }
    
    path[0]=0;
    
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
    
            if (path[u] == INT_MAX) 
            {
                continue;
            }
    
            if (path[u] + wt < path[v]) 
            {
                path[v] = path[u] + wt;
            }
        }
    }
    
    for(int i=1;i<n;i++)
    {
        if(path[i]!=INT_MAX)
        {
            cout<<path[i]<<" ";
        }
        else
        {
            cout<<"1000000000 ";
        }
    }
    cout<<endl;
}



class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const int INF = 1e8;
        vector<int> dist(V, INF);

        dist[src] = 0;

        // Step 1: Relax edges V-1 times
        for (int i = 1; i <= V - 1; i++) {
            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                if (dist[u] != INF && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Step 2: Check for negative weight cycle
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                return {-1};   // Negative cycle detected
            }
        }

        return dist;
       
        
    }
};
