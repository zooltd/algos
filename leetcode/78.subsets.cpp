#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
    
private:
    void dfs(vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(path);
            return;
        }
        
        path.push_back(nums[i]);
        dfs(nums, i + 1);

        path.pop_back();
        dfs(nums, i + 1);
    }
    
private:
    vector<vector<int>> res;
    vector<int> path;
};
// @lc code=end
