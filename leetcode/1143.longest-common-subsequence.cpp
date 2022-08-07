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
        int n = text1.length();
        int m = text2.length();
        text1 = " " + text1;
        text2 = " " + text2;
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
              if (text1[i] == text2[j])
                f[i][j] = f[i - 1][j - 1] + 1;
              else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        return f[n][m];
    }
};
// @lc code=end
