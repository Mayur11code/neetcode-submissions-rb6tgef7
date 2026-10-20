#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        // dp[i] represents whether s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        
        // Base case: empty string is valid
        dp[0] = true; 
        
        // i represents the ending length of the substring we are checking
        for (int i = 1; i <= n; i++) {
            for (const string& word : wordDict) {
                int len = word.length();
                
                // 1. Ensure the word isn't longer than our current substring
                if (i >= len) {
                    // 2. Check if the prefix before this word was valid (dp[i - len])
                    // 3. Check if the dictionary word matches the end of our current substring
                    if (dp[i - len] && s.substr(i - len, len) == word) {
                        dp[i] = true;
                        break; // Found a valid break for dp[i], no need to check other words
                    }
                }
            }
        }
        
        return dp[n];
    }
};