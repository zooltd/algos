#include <vector>
#include <unordered_map>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto* emp : employees) hash[emp->id] = emp;
        return dfs(id);
    }

    int dfs(int id) {
        auto* emp = hash[id];
        int ans = emp->importance;
        for (int sub_id : emp->subordinates)
            ans += dfs(sub_id);
        return ans;
    }

private:
    unordered_map<int, Employee*> hash;
};
// @lc code=end

