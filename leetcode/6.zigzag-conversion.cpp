/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int i = 0;
        int row = 0, col = 0;
        while(i < n) {
            for (row = 0; row < numRows && i < n; row++)
                a[row][col] = s[i++];
            for (row = numRows - 2; row >= 1 && i < n; row--)
                a[row][++col] = s[i++];
            ++col;
        }
        string res;
        for (int ii = 0; ii < numRows; ii++)
            for (int jj = 0; jj < col; jj++)
                if (a[ii][jj]) res.push_back(a[ii][jj]);
        return res;
    }
private:
    static const int N = 1000;
    char a[N][N];
};
// @lc code=end

