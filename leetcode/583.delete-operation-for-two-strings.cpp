#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        word1 = "1" + word1;
        word2 = "2" + word2;
        for (int i = 0; i <= m; i++) f[i][0] = i;
        for (int i = 1; i <= n; i++) f[0][i] = i;
        /*
        f[i][j] = {
            f[i - 1][j - 1], if word1[i] == word2[j]
            min(f[i - 1][j], f[i][j - 1]) + 1, if word1[i] != word2[j]
        }
        */
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i] == word2[j])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            }
        }
        return f[m][n];
    }
};
// @lc code=end

// LCS
class Solution2 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // lcs of word1 and word2
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        word1 = "1" + word1;
        word2 = "2" + word2;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i] == word2[j])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        int lcs = f[m][n];
        return m - lcs + n - lcs;
    }
};