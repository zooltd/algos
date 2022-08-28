#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4) return false;
        int target = sum / 4;
        sort(nums.begin(), nums.end(), greater<>());
        used.resize(nums.size(), false);
        return dfs(nums, target, 0, 0, 0);
    }
    
    // @curr: curr edge length
    // @cnt: # of completed edges / index of edge that is currently making up
    // @st: start index
    bool dfs(vector<int>& nums, int target, int curr, int cnt, int st) {
        if (cnt == 3) return true;
        if (curr == target) return dfs(nums, target, 0, cnt + 1, 0);
        
        for (int i = st; i < nums.size(); i++) {
            if (used[i]) continue;
            if (curr + nums[i] > target) continue;
            used[i] = true;
            if (dfs(nums, target, curr + nums[i], cnt, i + 1)) return true;
            used[i] = false;
            
            // pruning
            if (curr == 0 || curr + nums[i] == target) return false;
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        };
        
        return false;
    }
private:
    vector<bool> used;
};
// @lc code=end

