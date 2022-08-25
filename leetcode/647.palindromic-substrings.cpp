#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            // starting index: i, i
            result += extend(s, i, i, s.size());
            // starting index: i, i + 1
            result += extend(s, i, i + 1, s.size());
        }
        return result;
    }

    int extend(const string& s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
};
// @lc code=end

// dp
class Solution2 {
public:
    // https://programmercarl.com/0647.%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.html#%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92
    int countSubstrings(string s) {
        int n = s.size();
        // f[i][j]: if substrings s[i~j] is a palindromic string
        vector<vector<bool>> f(n, vector<bool>(n, false));
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] != s[j]) f[i][j] = false;
                else if (j - i <= 1 || f[i + 1][j - 1]) {
                        res++;
                        f[i][j] = true;
                    }
                }
            }

        return res;
    }
};