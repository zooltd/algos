/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    int n = words.size();
    sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    unordered_set<string> hash;
    unordered_set<string> res;
    for (auto &word : words) {
      if (word == "") continue;
      if (dfs(word, hash, res)) res.insert(word);
      hash.insert(word);
    }
    return vector<string>(res.begin(), res.end());
  }

  bool dfs(string word, unordered_set<string> &hash, unordered_set<string> &res) {
    if (word == "") return true;
    if (res.find(word) != res.end()) return true;
    int len = word.length();
    for (int i = 1; i <= len; i++) {
      string cur = word.substr(0, i);
      if (hash.find(cur) != hash.end() && dfs(word.substr(i, len - i), hash, res))
        return true;
    }
    return false;
  }
};
// @lc code=end
