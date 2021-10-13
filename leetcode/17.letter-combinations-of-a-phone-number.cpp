#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits == "")
      return {};
    input = digits;
    string output = "";
    dfs(output);
    return res;
  }

private:
  void dfs(string &output) {
    int n = output.size();
    if (n == input.size()) {
      res.push_back(output);
      return;
    }
    char ch = input[n];
    assert(ch >= '2' && ch <= '9');
    for (const char candidate : vec[ch - '0']) {
      output += candidate;
      dfs(output);
      output.pop_back();
    }
  }

private:
  string input;
  vector<vector<char>> vec = {{},
                              {},
                              {'a', 'b', 'c'},
                              {'d', 'e', 'f'},
                              {'g', 'h', 'i'},
                              {'j', 'k', 'l'},
                              {'m', 'n', 'o'},
                              {'p', 'q', 'r', 's'},
                              {'t', 'u', 'v'},
                              {'w', 'x', 'y', 'z'}};
  vector<string> res;
};
// @lc code=end
