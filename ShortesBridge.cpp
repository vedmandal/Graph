#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.


Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 


*/


   class pairs{
    public:
    int x;
    int y;
    pairs(int x,int y){
        this->x=x;
        this->y=y;
    }
   };
    

    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};


    void dfs(vector<vector<int>>&grid,queue<pairs>&q,int row,int col , vector<vector<bool>>&vis){

        vis[row][col]=true;
         q.push({row,col});
        for(int i=0;i<4;i++){
            int r=row+dir[i][0];
            int c=col+dir[i][1];

            if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || vis[r][c]==true || grid[r][c]==0) {
                continue;
            }
            
            dfs(grid,q,r,c,vis);
           

        }

    }
   
    int shortestBridge(vector<vector<int>>& grid) {

        queue<pairs>q;

        bool flag=false;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));

        for(int i=0;i<grid.size() and flag==false;i++){
            for(int j=0;j<grid[0].size() and flag==false;j++){
                if(grid[i][j]==1){
                    dfs(grid,q,i, j,vis);
                    flag=true;
                }

            }
        }

        int level=-1;

        while(!q.empty()){
            int s=q.size();
            level++;
            while(s--){
                pairs rem=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int r=rem.x+dir[i][0];
                    int c=rem.y+dir[i][1];

                    if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || vis[r][c]==true){
                        continue;
                    }

                    if(grid[r][c]==1){
                        return level;
                    }

                    q.push({r,c});
                    vis[r][c] = true;


                }
            }
        }



        return -1;
    }
