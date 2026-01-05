// User function Template for C++
/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = [[1, 1, 0, 0, 0],
            [1, 1, 0, 0, 0],
            [0, 0, 0, 1, 1],
            [0, 0, 0, 1, 1]]
Output: 1
Explanation:
grid[][] = [[1, 1, 0, 0, 0], 
            [1, 1, 0, 0, 0], 
            [0, 0, 0, 1, 1], 
            [0, 0, 0, 1, 1]]
        
        
  Example 2:

Input:
grid[][] = [[1, 1, 0, 1, 1],
            [1, 0, 0, 0, 0],
            [0, 0, 0, 0, 1],
            [1, 1, 0, 1, 1]]
Output: 3
Explanation:
grid[][] = [[1, 1, 0, 1, 1], 
            [1, 0, 0, 0, 0], 
            [0, 0, 0, 0, 1], 
            [1, 1, 0, 1, 1]]
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

*/

#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;


    string path="";
    void dfs(vector<vector<int>>&grid,int r,int c){
        
        grid[r][c]=0;
        
        if(r-1>=0 && grid[r-1][c]==1){
            path+="u";
            
            dfs(grid,r-1,c);
        }
        
        if(r+1<grid.size() && grid[r+1][c]==1){
            path+="d";
            dfs(grid,r+1,c);
        }
        
        if(c-1>=0 && grid[r][c-1]==1){
            path+="l";
            dfs(grid,r,c-1);
        }
        
        if(c+1<grid[0].size() && grid[r][c+1]==1){
            path+="r";
            dfs(grid,r,c+1);
            
        }
        
        path+="z";
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
       
       set<string>ans;
      
       
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]==1){
                   path="";
                   path+="x";
                   dfs(grid,i,j);
                   ans.insert(path);
               }
           }
       }
       return ans.size();
        
    }

