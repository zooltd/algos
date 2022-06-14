/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();    
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> res;
        for (int i = 0, x = 0, y = 0, d = 0; i < m * n; i++) {
            res.push_back(matrix[x][y]);
            visited[x][y] = true;

            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= m || b < 0 || b >= n || visited[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }

        return res;
    }

private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
};
// @lc code=end

