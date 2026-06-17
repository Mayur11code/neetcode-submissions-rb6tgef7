class Solution {
public:

        void backtrack(int startindex, vector<int> currstate, vector<vector<int>> &result , vector<int> &nums, int target){


            int sum = std::accumulate(std::begin(currstate), std::end(currstate), 0);

            if(sum==target){
            result.push_back(currstate);
            return;
            };
            if(sum>target){
                return;
            };


            for(int i = startindex ; i< nums.size() ; i++ ){
                
                currstate.push_back(nums[i]);
                backtrack(i, currstate , result, nums,target);
                currstate.pop_back();
                
            }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        vector<int> currstate;
        backtrack(0,currstate,result,nums,target);

        return result;


    }
};
