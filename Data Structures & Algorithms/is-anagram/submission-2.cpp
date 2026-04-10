class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
    return false;
}
        unordered_map<char,int> m;
        for(char c : s){
            m[c]++;
        }
        for(char d : t){
            if(m[d]==0){return false;}
            m[d]--;
        }
        
        
        return true;
    }
};
