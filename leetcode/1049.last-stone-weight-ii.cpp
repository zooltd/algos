#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
public:
    /**
    * @brief https://programmercarl.com/1049.%E6%9C%80%E5%90%8E%E4%B8%80%E5%9D%97%E7%9F%B3%E5%A4%B4%E7%9A%84%E9%87%8D%E9%87%8FII.html#%E6%80%9D%E8%B7%AF
    */
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> f(15001, 0);
        for (int i = 0; i < stones.size(); i++)
            for (int j = target; j >= stones[i]; j--)
                f[j] = max(f[j], f[j - stones[i]] + stones[i]);
        return sum - f[target] - f[target];
    }
};
// @lc code=end

