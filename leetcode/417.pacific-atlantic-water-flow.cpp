#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        if (m == 0 || n == 0) return {};
        visited.resize(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) dfs(heights, i, 0, 0x01);
        for (int i = 0; i < n; i++) dfs(heights, 0, i, 0x01);
        for (int i = 0; i < m; i++) dfs(heights, i, n - 1, 0x10);
        for (int i = 0; i < n; i++) dfs(heights, m - 1, i, 0x10);
        
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (visited[i][j] == 0x11)
                    res.push_back({i, j});
        return res;
    }

    void dfs(vector<vector<int>>& heights, int x, int y, int flag) {
        if (visited[x][y] & flag) return;
        visited[x][y] |= flag;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= m || b < 0 || b >= n) continue;
            if (heights[a][b] < heights[x][y]) continue;
            dfs(heights, a, b, flag);
        }
    }

private:
    int m;
    int n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> visited;
};
// @lc code=end

