/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        nums = matchsticks;
        if (nums.size() < 4) return false;
        visited.resize(nums.size(), false);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4) return false;
        int length = sum / 4;
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0, 0, length, 0);
    }
    
    /**
     * @param start starting index
     * @param curr current edge length
     * @param length target edge length
     * @param cnt completed edges
     */
    bool dfs(int start, int curr, int length, int cnt) {
        if (cnt == 3) return true;
        if (curr == length) return dfs(0, 0, length, cnt + 1);
        
        for (int i = start; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (curr + nums[i] <= length) {
                visited[i] = true;
                if (dfs(i + 1, curr + nums[i], length, cnt)) return true;
                visited[i] = false;
            }
            // fails => pruning
            if (curr == 0 || curr + nums[i] == length) return false;
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return false;
    }

private:
    vector<int> nums;
    vector<bool> visited; 
};
// @lc code=end

