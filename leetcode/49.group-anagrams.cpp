#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> map;
    for (auto &str : strs) {
      string cp = str;
      sort(cp.begin(), cp.end());
      map[cp].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto &pair : map)
      ans.push_back(pair.second);
    return ans;
  }
};
// @lc code=end
