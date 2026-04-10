class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high= nums.size()-1;
        int mid= (low+high)/2;
        if(nums[low]==target){ return low;}
        if(nums[high] == target){return high;}
        while(low<high){
            if(target == nums[mid]){
                return mid;

            }
            if(mid == low || mid == high){
                break;
            }
            else if (target < nums[mid]){
                high= mid;
                
            }
            else{
                low = mid;
            }
            
            mid = (low+high)/2;

          
        }

        return -1;
    }

};
