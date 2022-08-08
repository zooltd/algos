#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
    /**
    * https://www.acwing.com/solution/content/382/
    */
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        for (const string& str : strs) {
            int oneNum = 0, zeroNum = 0;
            for (const char c : str)
                if (c == '0') zeroNum++;
                else oneNum++;
            for (int i = m; i >= zeroNum; i--)
                for (int j = n; j >= oneNum; j--)
                    f[i][j] = max(f[i][j], f[i - zeroNum][j - oneNum] + 1);
        }
        return f[m][n];
    }
};
// @lc code=end

