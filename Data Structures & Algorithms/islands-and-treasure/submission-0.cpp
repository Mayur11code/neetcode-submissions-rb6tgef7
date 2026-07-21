class Solution {
public:

    int inf = 2147483647;
    int m,n;

    int direc[4][2]={{0,1}, {0,-1}, {1,0},{-1,0}};

    bool isValid(int r, int c, vector<vector<int>>& grid){
        return (r>=0 && r<m && c>=0 && c<n && grid[r][c]>0);
    }

    void dfs(int r, int c, vector<vector<int>>& grid, int currstep){

        for(auto& dir : direc){
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(isValid(nr,nc,grid)){
                
                if(grid[nr][nc]> currstep+1){
                    grid[nr][nc]= currstep +1;
                    dfs(nr,nc,grid,currstep+1);
                }
                
            }

            
        }
    }

    int hash(int r, int c){
        return r*(-10)+c;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        

        m = grid.size();
        n = grid[0].size();


        for(int i = 0 ; i <m ; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j]==0){
                   dfs(i,j,grid,0);
                }

            }
        }

    }
};
