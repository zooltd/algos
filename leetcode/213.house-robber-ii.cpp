#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    /**
    * https://leetcode.cn/problems/house-robber-ii/solution/213-da-jia-jie-she-iidong-tai-gui-hua-jie-gou-hua-/
    * https://programmercarl.com/0213.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DII.html#%E6%80%9D%E8%B7%AF
    */
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

    int robRange(vector<int>& nums, int st, int ed) {
        if (st == ed) return nums[st];
        vector<int> f(nums.size());
        f[st] = nums[st];
        f[st + 1] = max(nums[st], nums[st + 1]);
        for (int i = st + 2; i <= ed; i++)
            f[i] = max(f[i - 2] + nums[i], f[i - 1]);
        return f[ed];
    }
};
// @lc code=end

class Solution2 {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    nums.insert(nums.begin(), 0);
    int ans;
    // a cycle exists in a searching tree, cut the edge in the cycle
    // then handle 2 cases

    vector<vector<int>> f(n + 1, vector<int>(2, 0));
    f[0][1] = -1; // invalid

    // not rob the first house, can rob the n-th house
    f[1][0] = 0;
    f[1][1] = -1; // invalid
    for (int i = 2; i <= n; i++) {
      f[i][0] = max(f[i - 1][0], f[i - 1][1]);
      f[i][1] = f[i - 1][0] + nums[i];
    }
    ans = max(f[n][0], f[n][1]);

    // can rob the n-th house, not rob the n-th house
    f[1][0] = 0;
    f[1][1] = nums[1];
    for (int i = 2; i <= n; i++) {
      f[i][0] = max(f[i - 1][0], f[i - 1][1]);
      f[i][1] = f[i - 1][0] + nums[i];
    }
    ans = max(ans, f[n][0]);

    return ans;
  }
};