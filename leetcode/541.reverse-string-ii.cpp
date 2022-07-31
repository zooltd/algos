/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += k * 2) {
            int l = i, r = min(i + k, (int)s.size());
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }
};

class Solution2 {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        helper(s, n, k, 0);
        return s;
    }

    /**
     * @brief 
     * 
     * @param s string
     * @param n string size
     * @param k # reverse
     * @param st start idx of the sequence to be reversed
     */
    void helper(string& s, int n, int k, int st) {
        if (st >= n) return;
        if (n - st < k) return helper(s, n, n - st, st);
        for (int i = st, j = st + k - 1; i < j; i++, j--) swap(s[i], s[j]);
        return helper(s, n, k, st + 2 * k);
    }
};
// @lc code=end

