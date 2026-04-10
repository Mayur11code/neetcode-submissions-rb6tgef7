class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        vector<int> need(128, 0);
        for (char c : t) need[c]++;

        int match = t.length();
        int i = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int j = 0; j < s.length(); j++) {
            if (need[s[j]] > 0) match--;
            need[s[j]]--;

            while (match == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                need[s[i]]++;
                if (need[s[i]] > 0) match++;
                i++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
