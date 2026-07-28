class Solution {
public:


        class DSU{
            

       public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        iota(parent.begin(), parent.end(), 0);
        }

        int find(int x){
            if(parent[x]==x){
                return x; // root is x
            }
            return parent[x] = find(parent[x]);
        }


        bool unite(int x, int y){
           int rootx = find(x);
            int rooty = find(y);

            if(rootx == rooty){
                return false; //already connected, means cycle
            }

            if(rank[rootx]> rank[rooty]){
                parent[rooty]= rootx;
            }
            else if(rank[rooty]> rank[rootx]){
                parent[rootx]= rooty;
            }
            else{
                parent[rooty]=rootx;
                rank[rootx]++;
            }

            return true;


        }
        };

    bool validTree(int n, vector<vector<int>>& edges) {
     
        DSU* findun = new DSU(n);

        for(auto& e : edges){
            bool result = findun->unite(e[0], e[1]);
            if(!result){
                return result;
            }
        }

        bool tworoot = false;
        for(int i =0; i<n; i++){

            if(findun->parent[i]==i){
                if(tworoot){
                    return false;
                }
                tworoot = true;
            }
        }

        return true;


    }
};
