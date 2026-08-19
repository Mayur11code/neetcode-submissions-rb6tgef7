class Solution {
public:
    int rob(vector<int>& nums) {
        int am2 =0;
        int am1 = nums[0];
        
        
        for(int i=1; i<nums.size();i++){
            int am = max(nums[i]+am2,am1);
            am2=am1;
            am1 = am;
            
        }

        return max(am2,am1);



    }
};
