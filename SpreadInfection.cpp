                        
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src; 
    this->nbr = nbr;
  }
};
class Pair
{
public:
  int src = 0;
  int time = 0;
  Pair(int src, int time)
  {
    this->src = src;
    this->time = time; 
  }
};
 
 

int main() {                                                                            
 
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  

  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin >> u >> v >> w;
 
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));

  } 
  int src,t; 
  cin >> src;
  cin >> t; 

  vector<bool> visited(vtces,false);
  queue<Pair> q;  
  q.push(Pair(src,1));  
  int count = 0; 
  while(q.size()!= 0){    
    
    Pair rem = q.front();
    q.pop(); 
      if(visited[rem.src] == true){  
          continue;
      }
      visited[rem.src] = true;
      if(rem.time > t){
          break;
      }
      count++;
      for(Edge e: graph[rem.src]){
          if(visited[e.nbr] == false){
              q.push(Pair(e.nbr,rem.time+1));
          }
      }
  }
  cout<< count;
  return 0;
}
