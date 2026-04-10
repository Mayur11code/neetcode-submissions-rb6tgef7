class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0, j=1;
        int curr = 0, max = 0;
        while(i< prices.size() && j < prices.size()){
            if(prices[j]< prices[i]){
                i=j;
                j++;
                continue;
            }
            curr = prices[j] - prices[i];
            if(curr> max){ max = curr;}
            j++;

        
        }

        return max;

    }
};
