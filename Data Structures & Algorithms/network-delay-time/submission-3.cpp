class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto& edge: times){
            int source = edge[0];
            adj[source].push_back({edge[1], edge[2]});

        }

        vector<int> dist(n+1, 1e9);
        dist[k]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){

          auto [weight,target] = pq.top();
          pq.pop();

          if(dist[target]<weight){
            continue;
          }

          for(auto& [e,time] : adj[target]){
            if(dist[e] > weight+ time){
                dist[e] = weight+time;
                pq.push({dist[e], e});


            }

          }

        }


        int min = 0;
        for(int i=1; i<dist.size();i++){
            if(dist[i]>min){
                min = dist[i];
            }
        }

        return min == 1e9 ? -1 : min;
        


    }
};
