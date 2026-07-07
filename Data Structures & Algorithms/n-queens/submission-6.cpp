class Solution {
public:
    int hash(int x ,int y){
        return x*(-10) + y;
    }

    void markRowsAndCols(unordered_set<int> &board, int row, int col, int n) {
        for (int i = 0; i < n; i++) {
            board.insert(hash(row, i)); 
            board.insert(hash(i, col)); 
        }
    }

    void markDiagonals(unordered_set<int> &board, int row, int col,int n,int mode){

        int maxcells = n*n;
        if(mode == 0){
            markDiagonals(board, row, col, n, +1);
            markDiagonals(board, row, col, n, -1);
            markDiagonals(board, row, col, n, +2);
            markDiagonals(board, row, col, n, -2);
        }

        int x = row;
        int y = col;
        if(x<n && y<n && x>-1 && y>-1){
        if(mode == 1){

            int code = hash(x,y);
            board.insert(code);
            markDiagonals(board,x+1,y+1,n,+1); 
        }
        if(mode == -1){

            int code = hash(x,y);
            board.insert(code);
            markDiagonals(board,x-1,y-1,n,-1); 
        }
        if(mode == 2){

            int code = hash(x,y);
            board.insert(code);
            markDiagonals(board,x+1,y-1,n,+2); 
        }
        if(mode == -2){

            int code = hash(x,y);
            board.insert(code);
            markDiagonals(board,x-1,y+1,n,-2); 
        }
        }


    }


    string makeElement( int y, int n){
        string e = "";
        for(int i = 0; i<n ; i++){
            if(i==y){
                e+="Q";
            }
            else{
                e+=".";
            }
        }
        return e;
    }

     void backtrack(vector<vector<string>> &result, vector<string> currstate, unordered_set<int> board,int row,int col,int n){

        if(col!=-1){
            markDiagonals(board,row,col,n,0);
            markRowsAndCols(board, row, col, n);
        }
        if(currstate.size()==n && board.size()==n*n){
            result.push_back(currstate);
            return;
        }

        
        int x=row+1;
        if(x>=n){
            return;
        }
        for(int i = 0; i<n ; i++){
            int code = hash(x,i);
            if(!board.contains(code)){
                string e = makeElement(i,n);
                currstate.push_back(e);
                backtrack(result,currstate,board,x,i,n);
                currstate.pop_back();
                
            }
        }

    }


    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> result;
        vector<string> currstate;
        unordered_set<int> board;

        backtrack(result,currstate,board,-1,-1,n);
        return result;
        
    }
};
