class Solution {
public:

    class DSU{
        public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n){ 

            parent.resize(n+1);
            iota(parent.begin(), parent.end(),0);
            rank.resize(n+1);

        }

        int find(int x){

            if(x == parent[x]){
                return x; //root is x only
            }

            return parent[x]= find(parent[x]); // we find the top level root and reassign it to the parent of x
        }

       bool unite(int x, int y){
            int rootx = find(x);
            int rooty = find(y);
            

            if(rootx == rooty){
                return false;
            }

            if(rank[rootx]>rank[rooty]){
                parent[rooty]= rootx;
            }
            else if(rank[rooty]>rank[rootx]){
                parent[rootx]= rooty;
            }
            else{
                parent[rooty]=rootx;
                rank[rootx]++;
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
