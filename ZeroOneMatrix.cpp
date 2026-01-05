#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
iven an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]




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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        queue<pairs>q;
       
       for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==0){
                q.push({i,j});

            }else{
                mat[i][j]=-1;
            }
        }
       }

       while(!q.empty()){
        pairs rem=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int r=rem.x+dir[i][0];
            int c=rem.y+dir[i][1];
            if(r>=0 and c>=0 and r<mat.size() and c<mat[0].size() and mat[r][c]<0){
                mat[r][c]=mat[rem.x][rem.y]+1;
                q.push({r,c});
            }
        }




       }
       return mat;

        
    }
