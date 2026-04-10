class Solution {
public:
    bool isPalindrome(string s) {
        string m;
        for(auto &c : s){
            if(isalnum(c) && c != ' '){
                m+=tolower(c);
            }
        }

    
        for(int i=0,j = m.length()-1 ; i<j;){
            if(m[i]!=m[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
        
    }
};
