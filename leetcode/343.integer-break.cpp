#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
public:
/**
 *
f[i][j]: select from number 1 ~ i, 
the max product with sum == j

answer: f[n - 1][n]


1. f[i][j] = max(
    f[i - 1][j], 
    f[i - 1][j - i] * i, 
    f[i - 1][j - 2 * i] * i^2,
    ...,
    f[i - 1][j - s * i] * i^s
)
2. f[i][j - i] = max(
    f[i - 1][j - i],
    f[i - 1][j - 2 * i] * i,
    ...,
    f[i - 1][j - s * i] * i^(s - 1)
)

1 + 2 => 3

state transfer function:
3. f[i][j] = max(
    f[i - 1][j],
    f[i][j - i] * i
)


4. f[j] = max(
    f[j],
    f[j - i] * i
)
 *
 */
    int integerBreak(int n) {
        vector<int> f(n + 1, 1);
        for (int i = 2; i <= n - 1; i++)
            for (int j = i; j <= n; j++)
                f[j] = max(f[j], f[j - i] * i);
        return f[n];
    }
};
// @lc code=end

