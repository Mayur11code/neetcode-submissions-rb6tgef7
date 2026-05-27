class KthLargest {
public:
    struct Compare{
       bool operator()(int a, int b){
            return a>b;
        }
    };

    priority_queue<int, vector<int>, Compare> pq;
    int maxSize;

    KthLargest(int k, vector<int>& nums) {
        maxSize = k;
        for(auto& num : nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>maxSize){
            pq.pop();
        }
        return pq.top();
    }
};
