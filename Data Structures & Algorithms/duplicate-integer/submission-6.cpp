class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int &n : nums ){
            m[n]++;
        }
     
        for ( auto v : m){
            if(v.second>1){
                return true;
            };
        }
        return false;
    }
};