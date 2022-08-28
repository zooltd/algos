#include <string>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, 0);
        return res;
    }

    /**
    * @brief check for validation of parentheses pairs
    * @remark Rule-1: in any prefix of string, # of ( >= # of )
    * @remark Rule-2: in the end, # of ( == # of )
    *
    * @param idx: put ( or ) on the idx-th slot
    * @param cnt_l: # of ( 
    * @param cnt_r: # of )
    */
    void dfs(int n, int idx, int cnt_l, int cnt_r) {
        if (cnt_l < cnt_r) return;
        
        if (idx == 2 * n) {
            if (cnt_l == cnt_r) res.push_back(path);
            return;
        }

        path.push_back('(');
        dfs(n, idx + 1, cnt_l + 1, cnt_r);
        path.pop_back();

        path.push_back(')');
        dfs(n, idx + 1, cnt_l, cnt_r + 1);
        path.pop_back();
    }

private:
    string path;
    vector<string> res;
};
// @lc code=end

