#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto &ticket: tickets)
            g[ticket[0]][ticket[1]]++;
        target = (int) tickets.size() + 1;
        path.emplace_back("JFK");
        dfs("JFK");
        return path;
    }

    bool dfs(string from) {
        if (path.size() == target) return true;
        for (auto &[to, cnt] : g[from]) {
            if (!cnt) continue;
            cnt--;
            path.push_back(to);
            if (dfs(to)) return true;
            cnt++;
            path.pop_back();
        }
        return false;
    }

private:
    int target;
    vector<string> path;
    unordered_map<string, map<string, int>> g;
};
// @lc code=end

