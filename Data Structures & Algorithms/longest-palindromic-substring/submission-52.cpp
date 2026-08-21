class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ansL = 0;
        int ansR = 0;

        for (int i = 0; i < n; i++) {
            
            // -------- ODD LENGTH PALINDROME --------
            int l = i;
            int r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // Step back to the last valid matching bounds
            l++;
            r--;
            if (r - l > ansR - ansL) {
                ansL = l;
                ansR = r;
            }

            // -------- EVEN LENGTH PALINDROME --------
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // Step back to the last valid matching bounds
            l++;
            r--;
            if (r - l > ansR - ansL) {
                ansL = l;
                ansR = r;
            }
        }

        return s.substr(ansL, ansR - ansL + 1);
    }
};