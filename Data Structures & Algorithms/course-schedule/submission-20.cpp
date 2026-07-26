class Solution {
public:

    bool dfs(int node, unordered_set<int> s, unordered_map<int,vector<int>> &m, unordered_set<int>& safe ){
            
            if(!m.contains(node) || safe.contains(node)){
                return true;
            }
            vector<int> targets = m[node];
            bool result = true;
            for(auto& target : targets){
                if(s.contains(target)){
                    return false;
                   
                }
                s.insert(target);
                result = dfs(target,s,m,safe);
                if(!result){
                    return result;
                }
                s.erase(target);
                safe.insert(target);
            }
            return result;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,vector<int>> m;

        for(auto& p : prerequisites){
            int source = p[1];
            int target = p[0];

            m[source].push_back(target);
        }

        bool possible = true;
        unordered_set<int> safe;
        
        for(auto& [key,value]: m){
        unordered_set<int> s;
            s.insert(key);
            possible = dfs(key,s,m,safe);

            if(!possible){
                return possible;
            }
            safe.insert(key);
           
        }

        return possible;

    }
};
