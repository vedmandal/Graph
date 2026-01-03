                        
#include<iostream>
#include<vector>
using namespace std;

using namespace std;
  
   class Edge {
       public:
          int src=0;
          int nbr=0;

      Edge(int src, int nbr){
         this->src = src;
         this->nbr = nbr;
      }
   };
   
void getCmp(vector<vector<Edge>>& graph, vector<bool> &vis , int src, vector<int>&scomp){
    vis[src] = true;
    scomp.push_back(src);
    for(Edge ed : graph[src]){
        if(!vis[ed.nbr]){
           getCmp(graph , vis , ed.nbr , scomp);
        }
    }
 }
   
   int main(){
      int n;
      cin>>n;
      
      int k;
      cin>>k;
      
      vector<vector<Edge>> graph(n, vector<Edge>());;
      
     for(int e = 0; e < k; e++){
         int v1 ;
         int v2 ;
         cin>>v1>>v2;
         graph[v1].push_back(Edge(v1, v2));
         graph[v2].push_back(Edge(v2, v1));
      }

      vector<bool> vis(n , false);
      vector<vector<int>> comps;
     
      for(int i=0 ; i<n ;i++){
          if(vis[i] == false){
              vector<int> scomp;
              getCmp(graph , vis , i , scomp);
              comps.push_back(scomp);
          }
      }
      
      int pairs=0;
      for(int i=0;i<comps.size();i++){
         for(int j=i+1;j<comps.size();j++){  
          int sum = comps[i].size()*comps[j].size();
          pairs+=sum;
        }
      }
     cout<<pairs;      

  }
