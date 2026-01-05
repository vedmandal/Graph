#include<iostream>
#include<vector>


using namespace std;

int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
void dfs(vector<vector<int>>&arr,int r,int c,int clr){

    arr[r][c]=-clr;
    int count=0;
    for(int i=0;i<4;i++){
        int row=r+dir[i][0];
        int col=c+dir[i][1];

        if(row<0 || col<0 || row>=arr.size() ||col>=arr[0].size()|| abs(arr[row][col])!=clr){
            continue;
        }
        count++;

        if(arr[row][col]==clr){
            dfs(arr,row,col,clr);
        }

        

    }
    if(count==4){
            arr[r][c]=clr;
    }


}



int main(){
    int n,m;
    cout<<"Enter row and coloumn for array filling "<<endl;
    cin>>n>>m;

    vector<vector<int>>arr(n,vector<int>(m));

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cin>>arr[i][j];

        }
    }

    int r,c;
    cout<<"Enter index of starting point "<<endl;
    cin>>r>>c;
    int color;
    cout<<"Enter number yoy want to change the border into"<<endl;

    dfs(arr,r,c,arr[r][c]);

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(arr[i][j]<0){
                arr[i][j]=color;
            }
        }
    }
}