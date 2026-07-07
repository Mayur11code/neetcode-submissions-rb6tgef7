class Solution {
public:
    int hash(int x ,int y){
        return x*(-10) + y;
    }

    void markRowsAndCols(unordered_set<int> &rows,
                         unordered_set<int> &cols,
                         int row,
                         int col) {
        rows.insert(row);
        cols.insert(col);
    }

    void markDiagonals(unordered_set<int> &diag1,
                       unordered_set<int> &diag2,
                       int row,
                       int col) {
        diag1.insert(row - col);
        diag2.insert(row + col);
    }

    string makeElement(int y, int n){
        string e = "";
        for(int i = 0; i < n; i++){
            if(i == y) e += "Q";
            else e += ".";
        }
        return e;
    }

    void backtrack(vector<vector<string>> &result,
               vector<string> &currstate,
               unordered_set<int> rows,
               unordered_set<int> cols,
               unordered_set<int> diag1,
               unordered_set<int> diag2,
               int row,int col,int n){

    if(col!=-1){
        rows.insert(row);
        cols.insert(col);
        diag1.insert(row-col);
        diag2.insert(row+col);
    }

    if(currstate.size()==n){
        result.push_back(currstate);
        return;
    }

    int x=row+1;
    if(x>=n) return;

    for(int i=0;i<n;i++){
        if(!rows.contains(x) &&
           !cols.contains(i) &&
           !diag1.contains(x-i) &&
           !diag2.contains(x+i))
        {
            currstate.push_back(makeElement(i,n));
            backtrack(result,currstate,rows,cols,diag1,diag2,x,i,n);
            currstate.pop_back();
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> result;
        vector<string> currstate;

        unordered_set<int> rows;
        unordered_set<int> cols;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        backtrack(result, currstate, rows, cols, diag1, diag2, -1, -1, n);

        return result;
    }
};