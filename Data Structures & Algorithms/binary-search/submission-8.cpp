class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

while (left <= right) {
    // Master Tip: Use this to avoid integer overflow
    int mid = left + (right - left) / 2;

    if (nums[mid] == target) {
        return mid; // Found it
    } else if (nums[mid] < target) {
        left = mid + 1; // Target is in the right half
    } else {
        right = mid - 1; // Target is in the left half
    }
}
return -1; // Not found
    }

};
