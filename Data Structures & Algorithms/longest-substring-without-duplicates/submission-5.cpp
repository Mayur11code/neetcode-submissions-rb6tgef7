class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;

        unordered_set<char> cset;
        int i = 0, j = 0;
        int maxLen = 0;

        while (i < n && j < n) {
            if (cset.find(s[j]) == cset.end()) {
                cset.insert(s[j]);
                maxLen = max(maxLen, (int)cset.size());
                j++;
            } else {
                cset.erase(s[i]);
                i++;
            }
        }
        return maxLen;
    }
};
