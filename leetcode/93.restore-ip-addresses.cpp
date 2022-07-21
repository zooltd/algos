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

    void dfs(const string& s, int st, int cnt, string path) {
        if (st == s.size()) {
            if (cnt == 4) path.pop_back(), res.push_back(path);
            return;
        }

        if (cnt >= 4) return;

        for (int i = st, val = 0; i < s.size(); i++) {
            // skip leading zeros
            if (i > st && s[st] == '0') break;
            val = val * 10 + s[i] - '0';
            if (val > 255) break;
            // str = s[st, i]
            dfs(s, i + 1, cnt + 1, path + to_string(val) + ".");
        }
    }

private:
    vector<string> res;
};
// @lc code=end

