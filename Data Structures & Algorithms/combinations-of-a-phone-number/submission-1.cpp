class Solution {
public:

  
   void backtrack(string currstate, vector<string> &result, vector<string>&pad, string digits){

        if(digits.size()==0 ){
            if(!currstate.empty()){
            result.push_back(currstate);
            }
            return;
        }

            
            int index = digits[0] - '0';
            string alpha = pad[index];
            std::string right = digits.substr(1); 

            for(char b : alpha){
                currstate.push_back(b);
                backtrack(currstate,result,pad,right);
                currstate.pop_back();
            }





    }

    vector<string> letterCombinations(string digits) {

        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> result;
        string currstate = "";
        backtrack(currstate, result , pad, digits);

        return result;

        
    }
};
