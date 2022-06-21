/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end()); 
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int st) {
        if (path.size() == 3) {
            if (path[0] + path[1] > path[2])
                res++;
            return;
        }

        for (int i = st; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

private:
    int res{0};
    vector<int> path;
};
// @lc code=end

