class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> m;
        vector<int> v;

        for(int j=0; j<k; j++){
            m.insert(nums[j]);
        }
            v.push_back(*m.rbegin());

        int i =0, j= k-1;
        while(j<nums.size()-1){
            m.erase(m.find(nums[i]));

            i++;
            j++;
            m.insert(nums[j]);
            v.push_back(*m.rbegin());
        }
        return v;
    }
};

