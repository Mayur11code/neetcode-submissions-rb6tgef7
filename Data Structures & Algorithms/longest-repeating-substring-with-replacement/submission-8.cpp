class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() <= 1) return s.length();

        int i = 0, j = 0;
        int maxLen = 0;
        int curr = 0; // max frequency in window

        unordered_map<char,int> m;

        while (j < s.length()) {
            m[s[j]]++;
            curr = max(curr, m[s[j]]);

            if ((j - i + 1) - curr <= k) {
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else {
                m[s[i]]--;
                i++;
                j++;
            }
        }

        return maxLen;
    }
};
