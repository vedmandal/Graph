#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Rotten Oranges
Difficulty: MediumAccuracy: 46.02%Submissions: 195K+Points: 4Average Time: 20m
Given a matrix mat[][], where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cell have fresh oranges
2 : Cell have rotten oranges

Your task is to determine the minimum time required so that all the oranges become rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

Note: If it is impossible to rot every orange then simply return -1.

Examples:

Input: mat[][] = [[2, 1, 0, 2, 1], [1, 0, 1, 2, 1], [1, 0, 0, 2, 1]]
Output: 2
Explanation: Oranges at positions (0,0), (0,3), (1,3), and (2,3) will rot adjacent fresh oranges in successive time frames.
All fresh oranges become rotten after 2 units of time.
Input: mat[][] = [[2, 1, 0, 2, 1], [0, 0, 1, 2, 1], [1, 0, 0, 2, 1]]
Output: -1
Explanation: Oranges at positions (0,0), (0,3), (1,3), and (2,3) rot some fresh oranges,
but the fresh orange at (2,0) can never be reached, so not all oranges can rot.


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
    int orangesRot(vector<vector<int>>& mat) {
        queue<pairs>q;
        int fresh=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }else if(mat[i][j]==1){
                    fresh++;
                }
            }
        }
        
        if(fresh==0){
            return 0;
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
                    
                    if(r>=0 and c>=0 and r<mat.size() and c<mat[0].size() and mat[r][c]==1){
                        q.push({r,c});
                       mat[r][c]=0;
                       fresh--;
                    }
                }
            }
            
            
        }
        if(fresh==0){
                return level;
            }else{
                return -1;
            }
        
        
       
        
    }


