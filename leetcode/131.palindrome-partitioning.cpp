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

private:
    void dfs(string& s, int u) {
        if (u == s.size()) {
            res.push_back(path);
            return;
        } 

        for (int i = u; i < s.size(); i++) {
            string str = s.substr(u, i - u + 1);
            if (isPalindrome(str)) {
                path.push_back(str);
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) {
            i++;
            j--;
        }
        return i >= j;
    }

private:
    vector<vector<string>> res;
    vector<string> path;
};
// @lc code=end

