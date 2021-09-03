#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n == 0)
      return {""};
    if (mp.find(n) != mp.end())
      return mp[n];

    // segment:
    // (a)  b
    // --  --
    // k  n-k
    // Eg:
    // "((()))" => a: "((()))"" b: ""
    // "(())()" => a: "(())""   b: "()"
    // "()()()" => a: "()""     b: "()()"
    vector<string> res;
    for (int k = 1; k <= n; k++) {
      auto res_a = generateParenthesis(k - 1); // a
      auto res_b = generateParenthesis(n - k); // b
      for (auto &a : res_a)
        for (auto &b : res_b)
          res.push_back("(" + a + ")" + b);
    }
    mp[n] = res;
    return res;
  }

private:
  // memorize
  unordered_map<int, vector<string>> mp;
};
// @lc code=end
