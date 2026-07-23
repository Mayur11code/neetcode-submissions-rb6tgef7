class Solution {
public:

    int m, n;

    int direc[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool isValid(int r,int c, vector<vector<int>>& grid){
        return (r<m && r >= 0 && c<n && c>=0 && grid[r][c]==1);
    }



    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int min = 0;
        int fresh=0;

        queue<pair<int,int>> q;

        for(int i =0; i<m ; i++){
            for(int j = 0 ; j <n ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();
            int r = front.first;
            int c = front.second;
            for(auto& dir : direc){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(isValid(nr,nc,grid)){
                    if(grid[r][c]==2){
                        grid[nr][nc]=10*m+1;
                    }
                    else{
                        grid[nr][nc] = grid[r][c]+1;
                    }
                    min = grid[nr][nc]-10*m;
                    q.push({nr,nc});
                    fresh--;
                }

            }
        }
        return fresh == 0 ? min : -1;
    }
};
