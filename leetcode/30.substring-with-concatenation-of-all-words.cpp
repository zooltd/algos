#include <bits/stdc++.h>
using namespace std;

// ***To Be Optimized***

/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    words_map = countWords(words);
    int word_len = words[0].size();
    int word_num = words.size();
    int window_size = word_len * word_num;
    vector<int> ans;

    for (int st = 0; st + window_size <= s.size(); st++) {
      string str = s.substr(st, window_size);
      if (match(str, words))
        ans.push_back(st);
    }
    return ans;
  }

private:
  unordered_map<string, int> words_map;

  bool match(string &str, vector<string> &words) {
    int word_len = words[0].size();
    unordered_map<string, int> mp;
    for (int st = 0; st < str.size(); st += word_len) {
      mp[str.substr(st, word_len)]++;
    }
    return isEqual(mp, words_map);
  }

  bool isEqual(unordered_map<string, int> &a, unordered_map<string, int> &b) {
    if (a.size() != b.size())
      return false;
    for (auto &pair : a) {
      if (b.find(pair.first) == b.end() || pair.second != b[pair.first])
        return false;
    }
    return true;
  }

  unordered_map<string, int> countWords(vector<string> &words) {
    unordered_map<string, int> ans;
    for (string &word : words)
      ans[word]++;
    return ans;
  }
};
// @lc code=end
