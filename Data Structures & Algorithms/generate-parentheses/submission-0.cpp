class Solution {
public:

    void backtrack(string &currstate, vector<string> &result, unordered_map<string,int> hm){


        if(hm["("]==0 && hm[")"]==0){
            result.push_back(currstate);
            return;
        }
        
        if(hm["("]>hm[")"]){
            return;
        }
        else if(hm["("]<hm[")"]){
            string newstate;
            if(hm["("]>0){
            newstate= currstate + "(";
            hm["("]--;
            backtrack(newstate,result,hm);
            hm["("]++;
            };
            hm[")"]--;
            newstate = currstate + ")";
            backtrack(newstate, result ,hm);
        }
        else if(hm["("]==hm[")"]){

            currstate+="(";
            hm["("]--;
            backtrack(currstate,result,hm);

        }
        



    }

    vector<string> generateParenthesis(int n) {
        unordered_map<string,int> hm;
        vector<string> result;
        string currstate = "";

        hm["("] = n;
        hm[")"] = n;

        backtrack(currstate,result, hm);

        return result;
    }
};
