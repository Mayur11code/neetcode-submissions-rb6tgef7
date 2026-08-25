class Solution {
public:
    int countSubstrings(string s) {
        int count=0;

        for(int i=0;i<s.size();i++){

            int l=i;
            int r=i+1;

            // EVEN ASSUMPTION
            while(r<s.size() && l>-1 && s[l]==s[r] ){
                l--;
                r++;
                count++;
            }

            l=i;
            r=i;

            // ODD

            while( r<s.size() && l>-1 && s[r]==s[l]){
                l--;
                r++;
                count++;
            }


        }

        return count;
    }
};
