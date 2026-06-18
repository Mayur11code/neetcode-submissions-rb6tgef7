class Solution {
public:

    void backtrack(int startindex, vector<int> &currstate, vector<vector<int>> &result, vector<int> &candidates,int target ){

            int sum = std::accumulate(std::begin(currstate), std::end(currstate), 0);

            if(sum == target){
                result.push_back(currstate);
                return;
            }
            if(sum > target){
                return;
            }
        
            for(int i = startindex ; i< candidates.size() ; i++ ){

                if (i > startindex && candidates[i] == candidates[i - 1]) {
                    continue; 
                }

                    currstate.push_back(candidates[i]);
                    backtrack(i+1,currstate,result,candidates,target);
                    currstate.pop_back();                

            }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> currstate;
        vector<vector<int>> result;
     std::sort(candidates.begin(), candidates.end());
        backtrack(0,currstate, result ,candidates,target);

        return result;
    }
};
