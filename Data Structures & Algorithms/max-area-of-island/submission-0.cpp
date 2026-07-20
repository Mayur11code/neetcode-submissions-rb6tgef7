class Solution {
public:

    int m, n;

    int direc[4][2] = {{0,1}, {0,-1}, {1,0},{-1,0}};

    bool isValid(int r,int c, vector<vector<int>>& grid){
        return(r<m && r>=0 && c>=0 && c<n && grid[r][c]==1);
    }


    int dfs(int r, int c, vector<vector<int>>& grid){
        int area = 1;
        grid[r][c]=0;

        for(auto& dir : direc){
            int nr = r + dir[0];
            int nc = c + dir[1];
        
            if(isValid(nr,nc,grid)){
                area+= dfs(nr,nc,grid);
            }

        }

        return area;

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int max=0;

        for(int i = 0; i < m ; i++){
            for(int j = 0; j <n ; j++){
                if(grid[i][j]==1){
                    
                    int area = dfs(i,j,grid);
                    if(area > max){
                        max = area;
                    }

                }
            }
        }

        return max;
    }
};
