#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0;
        for (int ti = 0; ti < t.size() && si < s.size(); ti++)
            if (t[ti] == s[si]) si++;
        return si == s.size();
    }
};
// @lc code=end

// LCS
class Solution2 {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (s[i - 1] == t[j - 1])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        return f[m][n] == m;
    }
};

// opt for lots of coming `s`
class Solution3 {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> index(26);
        for (int i = 0; i < t.size(); i++)
            index[t[i] - 'a'].push_back(i);
        // position in t
        int pos = 0;
        for (const char ch: s) {
            auto entry = index[ch - 'a'];
            if (entry.empty()) return false;
            // first element that >= pos
            auto iter = lower_bound(entry.begin(), entry.end(), pos);
            if (iter == entry.end()) return false;
            else pos = (*iter) + 1;
        }
        return true;
    }
};