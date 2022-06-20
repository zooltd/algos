/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return res;
    }

    /**
     * @param u current index
     * @param k path size
     */
    void dfs(string &s, int u, int k, string path) {
        if (u == s.size()) {
            if (k == 4) {
                path.pop_back();
                res.push_back(path);
            }
            return;
        }

        if (k >= 4) return;

        for (int i = u, value = 0; i < s.size(); i++) {
            // check leading zeros
            if (i > u && s[u] == '0') break;
            value = value * 10 + s[i] - '0';
            if (value <= 255) dfs(s, i + 1, k + 1, path + to_string(value) + ".");
            else break;
        }
    }

private:
    vector<string> res;
};
// @lc code=end

