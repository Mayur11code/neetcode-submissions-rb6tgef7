class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=1;


        for(int i=1; i<nums.size();i++){
            int max=1;
            int j = i-1;
            while(j>=0){
                if(nums[j]< nums[i] && (dp[j]+ 1) > max){
                    max = dp[j] + 1;
                }
                j--;
            }

            dp[i] = max;
            
        }
        int max2 = 0;
        for(auto& d : dp){
            if (d>max2){max2 = d;}
        }
        return max2;
    }
};
