
    #include<iostream>
    #include<vector>
    #include<queue>

    using namespace std;

    /*
   you are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 


    
    */
    
    
    class pairs{
        public:
        int row;
        int col;
        int msf;
        pairs(int row,int col,int msf){
            this->row=row;
            this->col=col;
            this->msf=msf;
        }
    };

    class Comp {
    public:
        bool operator()(const pairs& a, const pairs& b) const {
            return a.msf > b.msf;
        }
    };

     
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pairs, vector<pairs>, Comp> q;

        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));

        q.push({0,0,grid[0][0]});

        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()){

            pairs rem= q.top();

            q.pop();

            if(rem.row==grid.size()-1 and rem.col==grid[0].size()-1){
                return rem.msf;
            }

            if(vis[rem.row][rem.col]==true){
                continue;
            }
            vis[rem.row][rem.col]=true;

             for(int i=0;i<4;i++){
                int r=rem.row+dir[i][0];
                int c=rem.col+dir[i][1];

                if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || vis[r][c]==true){
                    continue;
                }

                q.push({r,c,max(rem.msf,grid[r][c])});
             }




        }

        return 0;






        
    }
