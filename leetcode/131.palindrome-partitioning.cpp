#include <string>
#include <vector>
using namespace std;
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
    
    void dfs(string& s, int st) {
        if (st == s.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = st; i < s.size(); i++) {
            // cut after i
            string substr = s.substr(st, i - st + 1);

            if (!isPalindrome(substr)) continue;
            
            path.push_back(substr);
            dfs(s, i + 1);
            path.pop_back();
        }
    }
    
    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;
        while (l <= r && s[l] == s[r]) {
            l++, r--;
        }
        return l > r;
    }
    
private:
    vector<string> path;
    vector<vector<string>> res;
};
// @lc code=end

