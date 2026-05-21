class Solution {
public:
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            // For a Max-Heap: largest element stays at the top.
            // Returning true means 'a' has lower priority (moves down).
            int distA = (a[0] * a[0]) + (a[1] * a[1]);
            int distB = (b[0] * b[0]) + (b[1] * b[1]);
            return distA < distB; 
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        for (const auto& point : points) {
            pq.push(point);
            
            // Constrain the heap to size K
            // The moment it exceeds K, pop the top (which is the maximum distance)
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};