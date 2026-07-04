class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        if (j<i){
            return false;
        }

        while (i < j) {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[i])) {
                i++;
            } 
            // Skip non-alphanumeric characters from the right
            else if (!isalnum(s[j])) {
                j--;
            } 
            // Both are valid characters, compare them
            else {
                if (tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }



    void backtrack( string s , vector<string> currstate, vector<vector<string>> &result){

        bool valid = isPalindrome(s);
        if(valid){
            currstate.push_back(s);
            result.push_back(currstate);
            currstate.pop_back();
        }

        for(int i = 0; i < s.size(); i++ ){

            string left = s.substr(0,i);
            string right = s.substr(i);

            bool ispal = isPalindrome(left);

            if(ispal){
                currstate.push_back(left);
                backtrack(right,currstate,result);
                currstate.pop_back();
            }



        }


    }



    vector<vector<string>> partition(string s) {

        vector<string> currstate;
        vector<vector<string>> result;
        backtrack(s, currstate, result);
        
    return result;

        
    }
};
