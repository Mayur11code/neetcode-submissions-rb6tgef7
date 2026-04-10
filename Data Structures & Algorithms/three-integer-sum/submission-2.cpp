#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort is mandatory for two-pointer logic
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Step 2: Skip duplicates for the "Fixed" element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Standard Two-Pointer search for the remaining two numbers
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move pointers and skip duplicates
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } 
                else if (sum < 0) {
                    left++; // Need a larger sum
                } 
                else {
                    right--; // Need a smaller sum
                }
            }
        }
        return result;
    }
};