#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> khanAlgo(int n, vector<vector<int>>&graph){
 vector<int>indegree(n,0);
 for(int i=0;i<n;i++){
    for(int nbr:graph[i]){
        indegree[nbr]++;
        
    }
 }

 queue<int>q;
 for(int i=0;i<n;i++){
    if(indegree[i]==0){
        q.push(i);
    }
 }
vector<int>ans;
 
 while(!q.empty()){
    int rem=q.front();

    q.pop();

    ans.push_back(rem);

    for(int nbr:graph[rem]){
        indegree[nbr]--;
        if(indegree[nbr]==0){
            q.push(nbr);
        }
    }
 }

 if(ans.size()!=n){
    return {-1};
 }else{
    return ans;
 }



}


int main(){
    int v,e;
    cout<<"Enter vertex and Edge"<<endl;
    cin>>v>>e;

    vector<vector<int>>graph(v);

    for(int i=0;i<e;i++){
        int src,nbr;
        cout<<"Enter src and edge"<<endl;
        cin>>src>>nbr;
        graph[src].push_back(nbr);
    }

   
   vector<int>res= khanAlgo(v,graph);

    if (res.size() == 1 && res[0] == -1) {
        cout << -1 << endl;
    } else {
        for (int x : res) cout << x << " ";
        cout << endl;
    }

}