/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
       stack<char> st; 
       for (const char ch : s)
           if (st.size() && mp[st.top()] == ch) st.pop();
           else st.push(ch);
       return st.empty();
    }
private:
    unordered_map<char, char> mp {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };
};
// @lc code=end

