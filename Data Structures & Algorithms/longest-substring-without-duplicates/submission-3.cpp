class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s == " " || s.length ()==1){ return 1;}
        unordered_set<char> cset;
        int i=0,j=1;
        int max =0;
        cset.insert(s[i]);
        while(i< s.length() && j < s.length()){
            if(cset.find(s[j]) == cset.end()){
                cset.insert(s[j]);
               
                j++;

            }
            else{
                if(s[i] == s[j]){
                    cset.erase(s[i]);
                    i++;
                }
                else{
                while(s[i]!= s[j]){
                    cset.erase(s[i]);
                    i++;
                
                }
                cset.erase(s[i]);
                i++;
                cset.insert(s[j]);
                j++;}
            }

             int curr = cset.size();
                if(curr > max){ max = curr;}


        }
        
        return max;
        
    }
};
