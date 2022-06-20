/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res {{0}};
        for (int i = 0; i < n; i ++) {
            int k = 1 << i;
            for (int j = res.size() - 1; j >= 0; j--)
                res.push_back(res[j] + k);
        }
        return res;
    }
};
// @lc code=end

