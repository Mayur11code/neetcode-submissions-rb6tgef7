class Solution {
public:

   bool backtrack(int currindex, unordered_set<int> &visited, pair<int,int> p, string &word, int row,int col, vector<vector<char>> & board){

            if(currindex == word.size()-1){
                return true;
            }
            
            int top = p.first -1 > -1 ? p.first -1 : -1;
            int bottom = p.first + 1 < row ? p.first +1 : -1;
            int left = p.second -1 > -1 ? p.second -1 : -1;
            int right = p.second +1 < col ? p.second +1  : -1 ;
            bool result =false;
            if(top!=-1 && !visited.contains(top*(-5) + p.second)){
                if(board[top][p.second] == word[currindex +1]){
                    pair<int,int> pp;
                    pp.first = top;
                    pp.second = p.second;
                    int cell =top*(-5) + pp.second;
                    visited.insert(cell);
                   result= backtrack(currindex+1, visited,pp,word,row,col,board);
                    if(result){return result;}
                    visited.erase(cell);

                }
            }
            if(bottom!=-1 && !visited.contains(bottom*(-5) + p.second)){
                if(board[bottom][p.second] == word[currindex +1]){
                    pair<int,int> pp;
                    pp.first = bottom;
                    pp.second = p.second;
                    int cell =bottom*(-5) + pp.second;
                    visited.insert(cell);
                    result= backtrack(currindex+1, visited,pp,word,row,col,board);
                    if(result){return result;}
                    visited.erase(cell);

                }
            }
            if(left!=-1 && !visited.contains(p.first*(-5) + left)){
                if(board[p.first][left] == word[currindex +1]){
                    pair<int,int> pp;
                    pp.first = p.first;
                    pp.second = left;
                    int cell =pp.first*(-5) + left;
                    visited.insert(cell);
                    result =backtrack(currindex+1, visited,pp,word,row,col,board);
                    if(result){return result;}
                    visited.erase(cell);

                }
            }
            if(right!=-1 && !visited.contains(p.first*(-5) + right)){
                if(board[p.first][right] == word[currindex +1]){
                    pair<int,int> pp;
                    pp.first = p.first;
                    pp.second = right;
                    int cell =pp.first*(-5) + right;
                    visited.insert(cell);
                    result =backtrack(currindex+1, visited,pp,word,row,col,board);
                    if(result){return result;}
                    visited.erase(cell);
                }
            }
            
            return result;


    }


    bool exist(vector<vector<char>>& board, string word) {

        unordered_set<int> visited;
        pair<int,int> p ;
        bool result = false;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0 ; j < board[i].size(); j++){
                if(board[i][j]== word[0]){
                    p.first = i;
                    p.second = j;
                    int cell = i*(-5) +j;
                    visited.insert(cell);
                    result = backtrack(0,visited,p,word, board.size(), board[i].size(),board);
                    if(result){
                        return result;
                    }
                    visited.erase(cell);
                }
            }
        }

        return result;

    }
};
