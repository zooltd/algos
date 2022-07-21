/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
    }

    void dfs(int k, int n, int st) {
        if (path.size() == k) {
            if (n == 0) res.push_back(path);
            return;
        }
        
        for (int i = st; i <= 9 - (k - path.size()) + 1; i++) {
            if (n >= i) {
                path.push_back(i);
                dfs(k, n - i, i + 1);
                path.pop_back();
            }
        }
    }

private:
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

