class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& p : prerequisites){
            int source = p[1];
            int target = p[0];
            adj[source].push_back(target);
            indegree[target]++;
        }


        queue<int> q;
        for(int i =0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            order.push_back(front);
            
            vector<int> neigh = adj[front];
            for(auto& n : neigh){
                indegree[n]--;
                if(indegree[n]==0){
                    q.push(n);
                }
            } 
        }

        return order.size()==numCourses ? order : std::vector<int>();

    }
};
