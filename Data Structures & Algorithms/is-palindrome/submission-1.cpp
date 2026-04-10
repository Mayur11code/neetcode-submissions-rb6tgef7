#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[i])) {
                i++;
            } 
            // Skip non-alphanumeric characters from the right
            else if (!isalnum(s[j])) {
                j--;
            } 
            // Both are valid characters, compare them
            else {
                if (tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};