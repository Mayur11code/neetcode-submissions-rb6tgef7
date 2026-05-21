class Solution {
public:

     public : struct Compare {
    bool operator()(const vector<double>& a, const vector<double>& b) {
        // C++ priority_queue returns the "largest" element first by default.
        // Returning true means 'a' has lower priority than 'b' (moves down the tree).
        
        // For a MIN-heap (smallest 3rd element at the top):
        return a[2] > b[2]; 
        
    }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> result;

        priority_queue<vector<double>, vector<vector<double>>, Compare> pq;

        for(auto& cord : points){
            pq.push({static_cast<double>(cord[0]),static_cast<double>(cord[1]),(sqrt((cord[0]*cord[0]) + (cord[1]* cord[1])))});
        }

        for(int i = 0 ; i<k; i++){
            if(pq.empty()){
                break;
            }
            vector<double> top = pq.top();
            result.push_back({static_cast<int>(top[0]),static_cast<int>(top[1])});
            pq.pop();
        }

        return result;

    }

   
};
