class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long totalProductWithoutZero = 1;
        int zeroCount = 0;

        // Step 1: Analyze the zeros and the non-zero product
        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                totalProductWithoutZero *= num;
            }
        }

        vector<int> result(n, 0);

        // Step 2: Fill the result based on our three scenarios
        for (int i = 0; i < n; i++) {
            if (zeroCount == 0) {
                // Scenario 1: No zeros
                result[i] = totalProductWithoutZero / nums[i];
            } 
            else if (zeroCount == 1) {
                // Scenario 2: One zero. Only the zero index gets a value.
                if (nums[i] == 0) {
                    result[i] = totalProductWithoutZero;
                } else {
                    result[i] = 0;
                }
            }
            // Scenario 3: zeroCount > 1
            // Every element remains 0 (vector initialized with 0)
        }

        return result;
    }
};