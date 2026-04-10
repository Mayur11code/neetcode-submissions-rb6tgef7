class Solution {
public:
    string encode(vector<string>& strs) {
        string result = "";
        for (const string& s : strs) {
            // Correctly convert length to string and add delimiter
            result += to_string(s.length()) + "#" + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        
        while (i < s.length()) {
            // Find the delimiter starting from the current position
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            // Extract the length (can be multiple digits like "12#")
            int length = stoi(s.substr(i, j - i));
            
            // Move i to the start of the actual string (after the '#')
            i = j + 1;
            
            // Extract the actual string using the length
            result.push_back(s.substr(i, length));
            
            // Move i to the start of the next encoded block
            i += length;
        }
        
        return result;
    }
};