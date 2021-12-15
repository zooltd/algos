/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int j = 0;
    int ans = 0;
    for (int i = 0; i < g.size(); i++) {
      while (j < s.size() && s[j] < g[i])
        j++;
      if (j < s.size())
        j++, ans++;
    }
    return ans; 
  }
};
// @lc code=end
