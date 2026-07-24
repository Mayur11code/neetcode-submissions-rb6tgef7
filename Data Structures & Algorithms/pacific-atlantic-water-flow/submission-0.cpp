class Solution {
public:
    int m, n;

    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    bool dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             bool &pac,
             bool &atl)
    {
        if (visited[r][c])
            return true;

        visited[r][c] = true;

        // Current cell touches Pacific
        if (r == 0 || c == 0)
            pac = true;

        // Current cell touches Atlantic
        if (r == m - 1 || c == n - 1)
            atl = true;

        // Early stop
        if (pac && atl)
            return true;

        for (auto &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                heights[nr][nc] <= heights[r][c])
            {
                dfs(nr, nc, heights, visited, pac, atl);

                if (pac && atl)
                    return true;
            }
        }

        return false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                vector<vector<bool>> visited(
                    m, vector<bool>(n, false));

                bool pac = false;
                bool atl = false;

                dfs(i, j, heights, visited, pac, atl);

                if (pac && atl)
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};