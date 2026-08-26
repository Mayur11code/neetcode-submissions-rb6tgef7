class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int wn1 = 1;
        int wn2 = 1;

        for (int i = 1; i < s.size(); i++) {
            int current_1_step = (s[i] == '0') ? 0 : wn1;
            int current_2_step = ((s[i - 1] - '0') * 10 + (s[i] - '0') > 26 || s[i-1] == '0') ? 0 : wn2;
            
            if (current_1_step == 0 && current_2_step == 0) return 0;

            wn2 = wn1;
            wn1 = current_1_step + current_2_step;
        }

        return wn1;
    }
};