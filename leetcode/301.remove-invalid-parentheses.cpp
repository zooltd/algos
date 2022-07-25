#include <deque>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        deque<string> q;
        q.push_back(s);
        while (q.size()) {
            int cnt = q.size();
            for (int i = 0; i < cnt; i++)
                if (valid(q[i]))
                    res.push_back(q[i]);
            if (res.size()) return res;
            unordered_set<string> candidates;
            for (int i = 0; i < cnt; i++) {
                string t = q.front();
                q.pop_front();
                for (int j = 0; j < t.size(); j++)
                    candidates.insert(t.substr(0, j) + t.substr(j + 1));
            }
            for (const string& candidate : candidates)
                q.push_back(candidate);
        }
        return res;
    }

    /**
    * @brief check for validation of parentheses pairs
    * @remark Rule-1: in any prefix of string, # of ( > # of )
    * @remark Rule-2: in the end, # of ( == # of )
    */
    bool valid(const string& s) {
        int l = 0, r = 0;
        for(auto ch: s) {
            if (ch == '(') l++;
            else if (ch == ')') r++;
            if (l < r) return false;
        }
        return l == r;
    }

    bool valid2(const string& s) {
        stack<char> st;
        for (const char ch : s) {
            if ('a' <= ch && ch <= 'z') continue;
            if (st.size() && st.top() == '(' && ch == ')') st.pop();
            else st.push(ch);
        }
        return st.empty();
    }
};
// @lc code=end

