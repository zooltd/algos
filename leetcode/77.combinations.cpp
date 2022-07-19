#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return res;
    }
    
private:
    void dfs(int n, int k, int st) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = st; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }
private:
    vector<vector<int>> res;
    vector<int> path;
};

class Solution2 {
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return res;
    }
    
private:
    void dfs(int n, int k, int st) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = st; i <= n; i++) {
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }
private:
    vector<vector<int>> res;
    vector<int> path;
};

// @lc code=end
