class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        if(amount == 0){return 0;}
        dp[0]=0;

        for(int i=1; i<amount+1;i++){
           

            for(auto& coin : coins){
                int dpindex = i-coin;
                if (dpindex>=0 && dp[dpindex] !=-1 && ((dp[i]> dp[dpindex]+1) || dp[i]==-1)){
                    dp[i]= 1 + dp[dpindex];
                }
            }

        }

        return dp[amount]>0 ? dp[amount] : -1;
    }
};
