
#include<iostream>
#include<vector>

/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.




*/

using namespace std;


    void dfs(vector<vector<int>>&grid,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0){
            return;
        }
        grid[r][c]=0;
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r+1,c);
        dfs(grid,r,c-1);


    }


    int numEnclaves(vector<vector<int>>& grid) {

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1){
                   if(grid[i][j]==1){
                    dfs(grid,i,j);
                   }
                }
            }
        }
        int count=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
        
    }