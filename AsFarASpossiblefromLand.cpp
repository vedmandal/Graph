#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

 

Example 1:


Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:


Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

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


    int maxDistance(vector<vector<int>>& grid) {

        queue<pairs>q;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }

        if(q.size()==0 || q.size()==grid.size()*grid[0].size()){
            return -1;
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

                if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==1){
                    continue;
                }
                q.push({r,c});
                grid[r][c]=1;
            }

            }
            
         }


         return level;

        
    }
