class Solution {
public:
        struct Compare {
        bool operator()(pair<char,int> a, pair<char,int> b) {
            return a.second < b.second;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> m;
        for(auto& task : tasks){
            m[task]++;
        }

        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> pq;
        for(auto& it: m){
            int val = it.second;
            pq.push({it.first, val});
        }

        int maxfreq = pq.top().second;
        int noMax = 0;
        
        while(!pq.empty() && pq.top().second>= maxfreq){
            noMax++;
            pq.pop();
        }

        return max(static_cast<int>(tasks.size()), (maxfreq - 1) * (n + 1) + noMax);


    }
};
