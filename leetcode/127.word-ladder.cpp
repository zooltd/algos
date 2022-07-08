/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> s(wordList.begin(), wordList.end());
    unordered_map<string, int> dist;
    dist[beginWord] = 0;
    queue<string> q;
    q.push(beginWord);

    while (q.size()) {
      string t = q.front();
      q.pop();

      string tmp = t;
      for (int i = 0; i < t.size(); i++) {
        t = tmp;
        for (char j = 'a'; j <= 'z'; j++) {
          t[i] = j;
          if (t == tmp || s.find(t) == s.end() || dist.find(t) != dist.end())
            continue;
          dist[t] = dist[tmp] + 1;
          if (t == endWord) return dist[t] + 1;
          q.push(t);
        }
      }
    }
    return 0;
  }
};
// @lc code=end
