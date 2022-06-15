/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<bool> visited(n + 1, false);
        for (int i = n - 1; i >= 0; i--) {
            int opts = fact(i);
            for (int j = 1; j <= n; j++) {
                if (visited[j]) continue;
                if (opts < k) k -= opts;
                else {
                    res += to_string(j);
                    visited[j] = true;
                    break;
                }
            }
        }
        return res;
    }

private:
    int fact(int n) {
        return (n == 0) ? 1 : n * fact(n - 1);
    }
};
// @lc code=end

