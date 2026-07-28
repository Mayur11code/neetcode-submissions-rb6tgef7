class Solution {
public:

    class DSU{
        public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n){ 

            parent.resize(n);
            iota(parent.begin(), parent.end(),1);
            rank.resize(n);

        }

        int find(int x){

            if(x == parent[x-1]){
                return x; //root is x only
            }

            return parent[x-1]= find(parent[x-1]); // we find the top level root and reassign it to the parent of x
        }

       bool unite(int x, int y){
            int rootx = find(x);
            int rooty = find(y);
            

            if(rootx == rooty){
                return false;
            }

            if(rank[rootx-1]>rank[rooty-1]){
                parent[rooty-1]= rootx;
            }
            else if(rank[rooty-1]>rank[rootx-1]){
                parent[rootx-1]= rooty;
            }
            else{
                parent[rooty-1]=rootx;
                rank[rootx-1]++;
            }

            return true;

        }


    };


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        DSU* findun = new DSU(n);

        int answer;

        for(int i = 0 ; i<n ; i++){

            vector<int> e = edges[i];

            bool result = findun->unite(e[0], e[1]);

            if(!result){
                answer = i;
            }

        }

        return edges[answer];
        

    }
};
