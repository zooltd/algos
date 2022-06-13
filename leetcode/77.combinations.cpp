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
    void dfs(int n, int k, int i) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
                
        if (i > n || path.size() + n - i + 1 < k) return;
        
        path.push_back(i);
        dfs(n, k, i + 1);
        
        path.pop_back();
        dfs(n, k, i + 1);
    }
private:
    vector<vector<int>> res;
    vector<int> path;
};

// @lc code=end
