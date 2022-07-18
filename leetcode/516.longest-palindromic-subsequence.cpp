/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) f[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                f[i][j] = max(f[i][j - 1], f[i + 1][j]);
                if (s[i] == s[j]) f[i][j] = max(f[i + 1][j - 1] + 2, f[i][j]);
            }
        }
        return f[0][n - 1];
    }
};
// @lc code=end

