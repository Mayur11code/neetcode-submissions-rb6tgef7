class Solution {
public:
    void backtrack(int startindex, vector<int> &currstate, vector<vector<int>> &result , vector<int> &nums, unordered_set<int> &uniquestate){

            if(uniquestate.size()==nums.size()){
                result.push_back(currstate);
                return;
            }
            if(uniquestate.size() < currstate.size()){
                return;
            }

            for(int i = startindex ; i< nums.size() ; i++ ){
                
                if(currstate.empty() || !uniquestate.contains(nums[i])){
                currstate.push_back(nums[i]);
                uniquestate.insert(nums[i]);
                backtrack(0, currstate , result, nums, uniquestate);
                currstate.pop_back();
                uniquestate.erase(nums[i]);
                };
                
            }

    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currstate;
        vector<vector<int>> result;
        unordered_set<int> uniquestate;

        backtrack(0,currstate,result,nums, uniquestate);

        return result;

    }
   
};

