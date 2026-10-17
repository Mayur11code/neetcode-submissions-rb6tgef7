class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0; // Cost to reach index 0 (starts at 0)
        int prev1 = 0; // Cost to reach index 1 (starts at 0)

        // Loop up to exactly cost.size() because the "top" is one step past the end
        for (int i = 2; i <= cost.size(); i++) {
            // Min cost to reach current step 'i'
            int curr = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            
            // Shift the window forward
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1; // The final accumulated cost to reach the top
    }
};