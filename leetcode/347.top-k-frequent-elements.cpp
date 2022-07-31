#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    typedef pair<int, int> PII;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto cmp = [](const PII& l, const PII& r) {
            return l.second > r.second;
        };
        // min-heap
        priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
        unordered_map<int, int> mp;
        for (const int num : nums) mp[num]++;
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            pq.push(*iter);
            if (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (pq.size()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

