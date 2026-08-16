class Solution {
public:

    int hashed(int x, int y, vector<vector<int>>& points){
        return x*(500000000) -y*6;
    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        
priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        
        int xi = points[0][0];
        int yi = points[0][1];
        
        unordered_set<int> visited;
        visited.insert(hashed(xi,yi,points));

        for(int i=1; i<points.size();i++){
            
            int xj = points[i][0];
            int yj = points[i][1];
            int dist = abs(xi-xj) + abs(yi - yj);
            pq.push({dist, {xj,yj}});

        }

        int nodes = 1;
        int cost = 0;
        while(!pq.empty() && nodes<points.size()){
            pair<int, vector<int>> p = pq.top();
            pq.pop();

            if(visited.contains(hashed(p.second[0], p.second[1], points))){
                continue;
            }

            cost+= p.first;
            visited.insert(hashed(p.second[0],p.second[1], points));

            for(auto& point : points){
                if(hashed(point[0], point[1],points) != hashed(p.second[0], p.second[1],points)){

                    int xi = point[0];
                    int yi = point[1];

                    int xj = p.second[0];
                    int yj = p.second[1];

                    int dist = abs(xi-xj) + abs(yi - yj);
                    
                    pq.push({dist, {xi,yi}});
                }
            }

        }

        return cost;


    }
};
