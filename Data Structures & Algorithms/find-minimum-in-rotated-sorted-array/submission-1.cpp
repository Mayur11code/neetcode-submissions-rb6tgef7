class Solution {
public:
    int findMin(vector<int> &nums) {
        int left=0, right= nums.size()-1;
        while(left<=right){
            
           int mid = left + (right-left)/2;

            if(nums[mid]<=nums[(mid+1)%nums.size()] && nums[mid]<=nums[(mid-1)%nums.size()]){
                return nums[mid];
            }
            else if(nums[right]<nums[mid]){
                left =mid+1;

            }
            else{
                right = mid -1;
            }

        }
    return false;
        
    }
};
