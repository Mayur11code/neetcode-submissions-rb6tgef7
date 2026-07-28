class Solution {
    
public:
    class DSU{
        public:
        vector<int> parent;
        vector<int> rank;
        int components;

        DSU(int n){
            components = n;
            parent.resize(n);
            iota(parent.begin(),parent.end(),0);
            rank.resize(n);
        }

        int find(int x){
            if(parent[x]==x){
                return x;
            }

            return parent[x]= find(parent[x]);

        }

        void unite(int x, int y){
            int rootx = find(x);
            int rooty = find(y);

            if(rootx == rooty){
                return;
            }

            if(rank[rootx]>rank[rooty]){
                parent[rooty]= rootx;
            }
            else if(rank[rooty]> rank[rootx]){
                parent[rootx]= rooty;
            }
            else{
                parent[rooty]= rootx;
                rank[rootx]++;
            }

            components--;
        }

    };


    int countComponents(int n, vector<vector<int>>& edges) {

        DSU* findun = new DSU(n);

        for(auto& e : edges){
            findun->unite(e[0],e[1]);
           
        }

        return findun->components; 


    }
};
