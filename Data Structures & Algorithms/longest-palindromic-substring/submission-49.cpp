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
                
                // overwrite old streak only if new one is longer
                if(newR-newL+1 > streakR-streakL+1){
                    streakL = newL;
                    streakR = newR;
                }
                
                streak = 0; 
            } 
             
            int l = i-1; 
            int r = i+1; 
             
            if(isValid(r,n) && isValid(l,n)){ 
                
                if(s[l]!=s[r]){ 
                    if(s[l]==s[i]){ 
                        r--; 
                    } 
                    else if(s[r]==s[i]){ 
                        l++; 
                    } 
                    else{ 
                        continue; 
                    } 
                } 
                else{ 
                    l = i;
                    r = i;
                } 
 
                while(isValid(l,n) && isValid(r,n) && s[r]==s[l]){ 
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
 
            int tempL = i;
            int tempR = i;
                 
            if(isValid(l,n) && s[l]==s[i]){ 
                tempL = l;
                tempR = i;
            } 
            else if(isValid(r,n) && s[r]==s[i]){ 
                tempL = i;
                tempR = r;
            } 
             
            if(tempR-tempL+1 > ansR-ansL+1){ 
                ansL = tempL;
                ansR = tempR;
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