class Solution {
public:

    int m,n;

    int direc[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0} };

    bool isValid(int r ,int c, vector<vector<char>>& board){
        return (r<m && r>=0 && c<n && c>=0 && board[r][c]=='O');
    }

    int hashed(int r, int c){
        return r*(-m*n) + c;
        }

    void dfs(int r, int c, vector<vector<char>>& board, unordered_set<int>& bad){
        if(!isValid(r,c,board)){
            return;
        }

        bad.insert(hashed(r,c));

        for(auto& dir : direc){
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(isValid(nr,nc,board) && !bad.contains(hashed(nr,nc))){

                dfs(nr,nc,board,bad);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();
        unordered_set<int> bad;
        for(int i=0; i<m; i++){
            dfs(i,0,board,bad);
            dfs(i,n-1,board,bad);
        }
        for(int i=0; i<n; i++){
            dfs(0,i,board,bad);
            dfs(m-1,i,board,bad);
        }

        for(int i =0 ; i<m; i++){
            for(int j =0; j<n;j++){
                if(!bad.contains(hashed(i,j))){
                    board[i][j]='X';
                }
            }
        }

        

    }
};
