class Solution {
public:

   void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj, vector<string>& result, string key){


        while(!adj[key].empty()){
            string value = adj[key].top();
            adj[key].pop();

            dfs(adj,result,value);

        }
        if(adj[key].empty()){
            result.push_back(key);
        }

    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

        vector<string> result;

        for(auto& t : tickets){
            adj[t[0]].push({t[1]});
        }

       dfs(adj,result,"JFK");

       reverse(result.begin(), result.end());

       return result;

    }
};
