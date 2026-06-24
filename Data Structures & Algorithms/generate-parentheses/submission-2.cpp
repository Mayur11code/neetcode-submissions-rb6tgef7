class Solution {
public:

    void backtrack(int open, int close, int n, string &currstate, vector<string> &result) {
    if (open == n && close == n) {
        result.push_back(currstate);
        return;
    }

    if (open < n) {
        currstate.push_back('(');
        backtrack(open + 1, close, n, currstate, result);
        currstate.pop_back();
    }

    if (close < open) {
        currstate.push_back(')');
        backtrack(open, close + 1, n, currstate, result);
        currstate.pop_back();
    }
}

    vector<string> generateParenthesis(int n) {
      
        vector<string> result;
        string currstate = "";


        backtrack(0,0,n,currstate,result);

        return result;
    }
};
