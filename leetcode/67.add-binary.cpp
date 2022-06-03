/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        for (; i >= 0 && j >= 0; i--, j--) {
            int ai = ctoi(a[i]);
            int bj = ctoi(b[j]);
            int num = (ai + bj + carry) % 2;
            carry = (ai + bj + carry) / 2;
            res.insert(0, to_string(num));
        }
        while (i >= 0) {
            int ai = ctoi(a[i--]);
            int num = (ai + carry) % 2;
            carry = (ai + carry) / 2;
            res.insert(0, to_string(num));
        }

        while (j >= 0) {
            int bj = ctoi(b[j--]);
            int num = (bj + carry) % 2;
            carry = (bj + carry) / 2;
            res.insert(0, to_string(num));
        }
        if (carry) res.insert(0, "1");
        return res;
    }
private:
    int ctoi(char c) {
        return c == '1'? 1 : 0;
    }
};
// @lc code=end

