class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>> output ;
        map<vector<int>,vector<string>> m;
        for(auto s : strs){
            vector<int> arr(26);
            for(auto c : s){
                arr[c-'a']++;
            }

            m[arr].push_back(s);

        }

        for(auto v : m){
          output.push_back(v.second);  
        }


    return output;
    }
};
