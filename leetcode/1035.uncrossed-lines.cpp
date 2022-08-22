#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution {
public:
    // LCS 
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = nums1[0] == nums2[0];
        for (int i = 1; i < n; i++)
            f[0][i] = max(f[0][i - 1], (int) (nums1[0] == nums2[i]));
        for (int i = 1; i < m; i++)
            f[i][0] = max(f[i - 1][0], (int) (nums1[i] == nums2[0]));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
                if (nums1[i] == nums2[j])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }

        return f[m - 1][n - 1];
    }
};
// @lc code=end

class Solution2 {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (nums1[i - 1] == nums2[j - 1])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }

        return f[m][n];
    }
};