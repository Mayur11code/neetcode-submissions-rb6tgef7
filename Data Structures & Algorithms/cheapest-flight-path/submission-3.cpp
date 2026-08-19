class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

       vector<vector<pair<int,int>>> adj(n);
       for(auto& c : flights){
            int source = c[0];
            int target = c[1];
            int price = c[2];
            adj[source].push_back({target,price});
       } 
    
        vector<int> dist(n,99999999);
       queue<vector<int>> q;
       q.push({src,0});
       int maxsteps = k+2;
       int price = 99999999;

       while(maxsteps>0){
        int l =q.size();

        for(int i=0; i<l;i++){
        vector<int> curr = q.front();
        q.pop();
        int node = curr[0];
        int p = curr[1];

        if(node == dst && p<price){
            price = p;
            continue;
        }

        for(auto& n : adj[node]){
            int node = n.first;
            int pr = n.second + p;
            if(pr<dist[node]){
            q.push({node,pr});
            dist[node] = pr;
            }

        }
        }
        maxsteps--;

       }

        return price < 99999999 ? price :-1 ;

        
    }
};
