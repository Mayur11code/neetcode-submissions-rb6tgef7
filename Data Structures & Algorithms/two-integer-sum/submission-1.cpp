class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map stores: {Value : Index}
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement already exists in our map
            if (numMap.find(complement) != numMap.end()) {
                // If found, return the stored index and current index
                return {numMap[complement], i};
            }
            
            // If not found, add current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        // Return empty if no solution is found (though the problem usually guarantees one)
        return {};
    }
};