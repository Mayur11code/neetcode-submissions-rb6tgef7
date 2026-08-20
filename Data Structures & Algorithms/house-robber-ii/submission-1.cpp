class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

    // CASE 1: first element is included
    int am1 = nums[0];
    int am2 = 0;

    for(int i=1;i<nums.size()-1;i++){
        int am = max(nums[i]+ am2, am1);
        am2 = am1;
        am1 = am;
    }

    int case1 = max(am1,am2);

    // CASE 2 : Last element is included
    int wm1= nums[1];
    int wm2 = 0;
    for(int i=2; i<nums.size();i++){
        int am = max(nums[i]+wm2, wm1);
        wm2 = wm1;
        wm1 = am;
    }

    int case2 = max(wm1,wm2);

    return max(case1, case2);


    }
};
