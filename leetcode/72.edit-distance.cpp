#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        word1 = " " + word1;
        word2 = " " + word2;

        for (int i = 0; i <= n; i++) f[0][i] = i;
        for (int i = 1; i <= m; i++) f[i][0] = i;
        
        /*
        f[i][j] = {
            if (word1[i] == word2[j])
                f[i - 1][j - 1]
            else
                // insert
                min(f[i - 1][j], f[i][j - 1]) + 1
                // delete
                min(f[i - 1][j], f[i][j - 1]) + 1
                // replace
                f[i - 1][j - 1] + 1
        }
        */
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i] == word2[j])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
            }
        }
        return f[m][n];
    }
};
// @lc code=end

