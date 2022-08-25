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
        if (digits.empty()) return {};
        dfs(digits, 0);
        return res;
    }
    
    void dfs(const string& digits, int st) {
        if (st == digits.size()) {
            res.push_back(path);
            return;
        }
        vector<char> candidates = vec[digits[st] - '0'];
        for (int num : candidates) {
            path.push_back(num);
            dfs(digits, st + 1);
            path.pop_back();
        }
    }
    
private: 
    string path;
    vector<string> res;
    vector<vector<char>> vec = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
};

// @lc code=end
