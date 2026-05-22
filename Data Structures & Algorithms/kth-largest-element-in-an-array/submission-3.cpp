class Solution {
public:
    struct Compare {
        bool operator()(int a, int b) {
            return a > b;
        }
    };

    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, Compare> pq;


        for(int& a : nums){
            pq.push(a);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
