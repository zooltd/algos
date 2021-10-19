#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> mp;
    for (auto &w : words)
      mp[w]++;

    auto comp = [&](const pair<string, int> &a, const pair<string, int> &b) {
      return a.second < b.second || (a.second == b.second && a.first > b.first);
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)>
        pq(comp);

    for (auto &p : mp)
      pq.emplace(p);

    vector<string> ans;
    while (!pq.empty() && k--) {
      ans.push_back(pq.top().first);
      pq.pop();
    }
    return ans;
  }
};
// @lc code=end
