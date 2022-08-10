#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // f[i]: can the substr with first i chars be segmented
        vector<int> f(n + 1, false);
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        f[0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++) {
                if (f[i]) break;
                if (hash.count(s.substr(j, i - j)))
                    f[i] |= f[j];
            }
        return f[n];
    }
};
// @lc code=end

class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> f(n + 1);
        f[0] = true;
        for (int i = 0; i < n; i++) {
            if (!f[i]) continue;
            for (const string& word : wordDict ) {
                if (i + word.size() <= n && s.substr(i, word.size()) == word)
                    f[i + word.size()] = true;
            }
        }
        return f[n];
    }
};