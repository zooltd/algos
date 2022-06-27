/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j]) ans = max(ans, dfs(grid, i, j));
        return ans;
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int ans = 1;
        grid[x][y] = 0;
        for (int d = 0; d < 4; d++) {
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= grid.size() || b < 0 || b >= grid[0].size() || !grid[a][b]) continue;
            ans += dfs(grid, a, b);
        }
        return ans;
    }
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0 , -1};
};
// @lc code=end

