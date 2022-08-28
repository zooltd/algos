#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    /*
    1: 0, 1
    2: 00, 01,| 11, 10
    3: 000, 001,| 011, 010,| 110, 111, 101, 100  
    */
    vector<int> grayCode(int n) {
        if (n == 1) return {0, 1};
        auto left = grayCode(n - 1);
        int sz = left.size();
        for (int i = sz - 1; i >= 0; i--) {
            left.push_back(left[i] | 1 << (n - 1));
        }
        return left;
    }
};
// @lc code=end

class Solution2 {
public:
    vector<int> grayCode(int n) {
        vector<int> res {{0}};
        for (int i = 0; i < n; i ++) {
            int k = 1 << i;
            for (int j = res.size() - 1; j >= 0; j--)
                res.push_back(res[j] + k);
        }
        return res;
    }
};