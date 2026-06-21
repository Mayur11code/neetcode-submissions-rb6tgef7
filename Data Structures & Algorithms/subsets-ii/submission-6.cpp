class Solution {
public:

    void backtrack(vector<int> &currstate,vector<int> &nums, vector<vector<int>> &result, int index){

        result.push_back(currstate);
        int count = 0;


        for(int i = index; i < nums.size(); i++){

            if(i!= nums.size()-1 && nums[i] == nums[i+1]){
                count++;
                continue;
            }

            for(int j = 0; j < count+1; j++){
                currstate.push_back(nums[i]);
                backtrack(currstate, nums, result,i+1);
            }
            for(int j = 0; j < count+1; j++){
                currstate.pop_back();
            }
            
            count = 0;
        


        }




    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());

        vector<int> currstate;
        vector<vector<int>> result;

        backtrack(currstate,nums,result,0);

        return result;
    }
};
