#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

// Custom hash functor required for unordered_set of pairs
struct PairHash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

class Solution {
public:
    int m, n;
    int direc[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    using PairSet = unordered_set<pair<int, int>, PairHash>;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        m = heights.size();
        n = heights[0].size();

        PairSet pac;
        PairSet atl;

        // Trigger DFS from the Pacific borders (Top and Left)
        for(int i = 0; i < m; i++) dfs(i, 0, heights, pac);
        for(int j = 0; j < n; j++) dfs(0, j, heights, pac);

        // Trigger DFS from the Atlantic borders (Bottom and Right)
        for(int i = 0; i < m; i++) dfs(i, n - 1, heights, atl);
        for(int j = 0; j < n; j++) dfs(m - 1, j, heights, atl);

        // Intersection: Find cells present in both ocean sets
        vector<vector<int>> result;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac.count({i, j}) && atl.count({i, j})){
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void dfs(int r, int c, vector<vector<int>>& heights, PairSet& oceanSet) {
        // If already evaluated and reachable from this ocean, skip to avoid cycles
        if (oceanSet.count({r, c})) return;

        // Since we only call DFS on valid paths moving upward, this cell is officially reachable!
        oceanSet.insert({r, c});

        for(int i = 0; i < 4; i++) {
            int nr = r + direc[i][0];
            int nc = c + direc[i][1];

            // 1. Check grid boundaries
            if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                // 2. Water flows to ocean, so heights must go UP or stay EQUAL as we move inland
                if(heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, heights, oceanSet);
                }
            }
        }
    }
};
