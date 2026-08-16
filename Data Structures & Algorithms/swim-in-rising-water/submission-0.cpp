class Solution {
public:

   int direc[4][2] ={{0,1},{0,-1},{1,0},{-1,0}};
int n =0;

    bool isValid(int x, int y){
        return (x>-1 && x<n && y>-1 && y<n);
    }

    int buck(int x, int y){
        return x*n + (y);
    }


    int swimInWater(vector<vector<int>>& grid) {
         n = grid.size();
        int t = grid[n-1][n-1];

        vector<bool> visited(n*n, false);

        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

        
        
        pq.push({grid[0][0],{0,0}});
        


        while(!pq.empty()){

            pair<int,vector<int>> p = pq.top();

            pq.pop();

            if(visited[buck(p.second[0], p.second[1])]){
                continue;
            }
            visited[buck(p.second[0], p.second[1])]=true;
            
            if(p.second[0]==n-1 && p.second[1]==n-1){
                return t;
            }
            int elev = p.first;

            if(elev > t){
                t=elev;
            }

            for(auto& dir : direc){
                int nr = p.second[0]+ dir[0];
                int nc = p.second[1]+ dir[1];

                if(isValid(nr,nc) && !visited[buck(nr,nc)]){
                    pq.push({grid[nr][nc],{nr,nc}});
                    
                }

            }

            



        }


        return t;




    }
};
