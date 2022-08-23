#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        dfs(digits, "", 0);
        return res;
    }

private:
    void dfs(string &digits, string path, int st) {
        if (st == digits.size()) {
            res.push_back(path);
            return;
        }
        for (const string s: index[digits[st] - '0']) {
            path += s;
            dfs(digits, path, st + 1);
            path.pop_back();
        }
    }

private:
    vector<string> res;
    vector<vector<string>> index = {
            {},
            {},
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}};
};
// @lc code=end
