#include<iostream>
#include<vector>
using namespace std;

void countIslands(vector<vector<int>>&arr,vector<vector<bool>>&vis,int i,int j){
   if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || vis[i][j]==true || arr[i][j]==1){
    return ;
   }

   vis[i][j]=true;

   countIslands(arr,vis,i-1,j);
   countIslands(arr,vis,i,j+1);
   countIslands(arr,vis,i,j-1);
   countIslands(arr,vis,i+1,j);




}


int main(){

    int n,m;
    cout<<"Enter rows and colums"<<endl;
    cin>>n>>m;

    vector<vector<int>>arr(n,vector<int>(m));

   


     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            cin>> arr[i][j];

          }
     }
      vector<vector<bool>>visited(n,vector<bool>(m,false));
      int c=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0 and visited[i][j]==false){
                countIslands(arr,visited,i,j);
                c++;

            }
        }
      }

      cout<<c<<endl;



    




}