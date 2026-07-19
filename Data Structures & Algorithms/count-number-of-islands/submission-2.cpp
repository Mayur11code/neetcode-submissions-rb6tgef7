class Solution {
public:
    int m, n;

    int direc[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool isValid(int r,int c, int m , int n, vector<vector<char>>& grid){
        return (r>=0 && r <m && c>=0 && c<n && grid[r][c]=='1');
    }

    void dfs(int r, int c, vector<vector<char>>& grid){

        grid[r][c] = '0';

        for(auto& dir : direc){
            int nr = r + dir[0];
            int nc = c + dir[1];

            if(isValid(nr,nc,m,n,grid)){
                dfs(nr,nc,grid);
            }
        }

    }


    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }

        return count;
    }
};
