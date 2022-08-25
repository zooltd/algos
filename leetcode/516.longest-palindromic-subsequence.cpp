#include <string>
#include <vector>
using namespace std;
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
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = 0; i < n; i++) f[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                f[l][r] = max(f[l + 1][r], f[l][r - 1]);
                if (s[l] == s[r])
                    f[l][r] = max(f[l][r], f[l + 1][r - 1] + 2);
            }
        }
        return f[0][n - 1];
    }
};
// @lc code=end

