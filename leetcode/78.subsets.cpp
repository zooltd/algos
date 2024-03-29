#include <vector>
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
    
    void dfs(vector<int>& nums, int st) {
        res.push_back(path);
        for (int i = st; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
    
private:
    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end
