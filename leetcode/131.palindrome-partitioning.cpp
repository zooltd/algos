/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }

    void dfs(string &s, int st) {
        if (st == s.size()) {
            res.push_back(path);
            return;
        }
        for (int ed = st; ed < s.size(); ed++) {
            string str = s.substr(st, ed - st + 1);
            if (!isPalindrome(str)) continue;
            path.push_back(str);
            dfs(s, ed + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(string& str) {
        for (int l = 0, r = str.size() - 1; l <= r; l++, r--)
            if (str[l] != str[r]) return false;
        return true;
    }

private:
    vector<vector<string>> res;
    vector<string> path;
};
// @lc code=end

