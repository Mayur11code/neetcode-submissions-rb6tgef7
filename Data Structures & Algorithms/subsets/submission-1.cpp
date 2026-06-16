class Solution {
public:

    void backtrack(int startindex, vector<int> currstate, vector<vector<int>> &result , vector<int> &nums){

            result.push_back(currstate);

            for(int i = startindex ; i< nums.size() ; i++ ){
                
                currstate.push_back(nums[i]);
                backtrack(i+1, currstate , result, nums);
                currstate.pop_back();
            }

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currstate;

        backtrack(0,currstate,result, nums);

        return result;

    }
};
