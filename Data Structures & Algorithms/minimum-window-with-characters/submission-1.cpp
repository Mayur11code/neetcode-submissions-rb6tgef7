class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        vector<int> freq(128, 0);
        for (char c : t) freq[c]++;

        int match = t.length();
        int i = 0;
        int start = 0;
        int minLen = s.length() + 1;   // just a large impossible length

        for (int j = 0; j < s.length(); j++) {
            if (freq[s[j]] > 0) match--;
            freq[s[j]]--;

            while (match == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                freq[s[i]]++;
                if (freq[s[i]] > 0) match++;
                i++;
            }
        }

        if (minLen > s.length()) return "";
        return s.substr(start, minLen);
    }
};
