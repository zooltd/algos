#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    /**
    * @brief f[n]= ∑ f[k] ∗ f[n − 1 − k], k = 0 ~ n - 1
    * 
    */
    int numTrees(int n) {
        vector<int> f(n + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= i; j ++ )
                f[i] += f[j - 1] * f[i - j];
        return f[n];
    }
};
// @lc code=end

