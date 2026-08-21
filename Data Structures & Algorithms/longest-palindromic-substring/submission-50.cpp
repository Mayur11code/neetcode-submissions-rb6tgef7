class Solution { 
public: 
 
    bool isValid(int index,int n){ 
        return (index>-1 && index<n); 
    } 
 
    string longestPalindrome(string s) { 
 
        string p = ""; 
        int n = s.size(); 
        int streak = 0; 
 
        int streakL = 0;
        int streakR = 0;
        int ansL = 0;
        int ansR = 0;
 
        for(int i=0; i<s.size(); i++){ 
             
            if(isValid(i-1,n) && s[i]==s[i-1]){ 
                streak++; 
            } 
 
            if(isValid(i-1,n) && (s[i]!=s[i-1] || i==s.size()-1)){ 
                
                int newL;
                int newR;
                
                if(i==s.size()-1 && s[i]==s[i-1]){
                    newL = i-streak;
                    newR = i;
                }
                else{
                    newL = i-1-streak;
                    newR = i-1;
                }
                
                if(newR-newL+1 > streakR-streakL+1){
                    streakL = newL;
                    streakR = newR;
                }
                
                streak = 0; 
            } 
             
            // -------- ODD LENGTH PALINDROME --------
            int l = i;
            int r = i;
 
            while(isValid(l,n) && isValid(r,n) && s[l]==s[r]){
                l--;
                r++;
            }
 
            l++;
            r--;
 
            if(r-l+1 > ansR-ansL+1){
                ansL = l;
                ansR = r;
            }
 
            // -------- EVEN LENGTH PALINDROME --------
            l = i;
            r = i+1;
 
            while(isValid(l,n) && isValid(r,n) && s[l]==s[r]){
                l--;
                r++;
            }
 
            l++;
            r--;
 
            if(r-l+1 > ansR-ansL+1){
                ansL = l;
                ansR = r;
            }
        } 
 
        // Compare longest streak with longest palindrome
        if(streakR-streakL+1 > ansR-ansL+1){
            ansL = streakL;
            ansR = streakR;
        }

        // Create the string only once
        p = s.substr(ansL, ansR-ansL+1);
 
        return p; 
    } 
};