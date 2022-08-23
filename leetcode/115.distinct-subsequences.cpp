#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();

        // f[i][j]: the number of distinct subsequences of s[:i] which equals t[:j].
        vector<vector<unsigned>> f(m + 1, vector<unsigned>(n + 1, 0));
        for (int i = 0; i < m; i++) f[i][0] = 1;
        for (int j = 1; j < n; j++) f[0][j] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = f[i - 1][j];
                if (s[i - 1] == t[j - 1])
                    f[i][j] += f[i - 1][j - 1];
            }
        }
        return f[m][n];
    }
};
// @lc code=end

