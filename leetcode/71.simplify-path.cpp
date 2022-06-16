/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> deq;
        for (int i = 0; i < path.size(); ) {
            if (path[i] == '/') {
                i++;
                continue;
            }
            int j = i + 1;
            while (j < path.size() && path[j] != '/') j++;
            string tmp = path.substr(i, j - i);
            if (tmp == ".." && deq.size()) deq.pop_back();
            else if (tmp != ".." && tmp != ".") deq.push_back(tmp);
            i = j;
        }

        string res = "/";
        while (deq.size()) {
            res += deq.front() + "/";
            deq.pop_front();
        }
        if (res.size() > 1) res.pop_back();

        return res;
    }
};
// @lc code=end

