#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (text1[i - 1] == text2[j - 1])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        return f[m][n];
    }
};
// @lc code=end

