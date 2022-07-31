#include <string>
using namespace std;
/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (const char ch : s) {
            if (res.size() && res.back() == ch) {
                res.pop_back();
                continue;
            }
            res.push_back(ch);
        }
        return res;
    }
};
// @lc code=end

