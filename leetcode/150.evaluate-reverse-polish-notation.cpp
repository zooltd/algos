#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <functional>
using namespace std;
/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const string& str : tokens) {
            auto iter = mp.find(str);
            if (iter == mp.end()) {
                stk.push(str2int(str));
            } else {
                auto func = iter->second;
                int y = stk.top();
                stk.pop();
                int x = stk.top();
                stk.pop();
                int value = func(x, y);
                stk.push(value);
            }
        }
        return stk.top();
    }

private:
    int str2int(const string& str) {
        int stIdx = 0;
        if (str[0] == '-') stIdx = 1;
        int value = 0;
        for (int i = stIdx; i < str.size(); i++)
            value = value * 10 + str[i] - '0';
        return stIdx ? -value : value;
    }

private:
    unordered_map<string, function<int(int, int)>> mp = {
        {"+", [](int x, int y) {return x + y;}},
        {"-", [](int x, int y) {return x - y;}},
        {"*", [](int x, int y) {return x * y;}},
        {"/", [](int x, int y) {return x / y;}},
    };
};
// @lc code=end

