/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert_1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        vector<vector<int>> res;
        intervals.insert(lower_bound(intervals.begin(), intervals.end(), newInterval), newInterval);
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= r)
                r = max(r, intervals[i][1]);
            else {
                res.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            }
        }

        res.push_back({l, r});
        return res;
    }

    vector<vector<int>> insert_2(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /* diff */
        vector<pair<int, int>> events;
        for (vector<int> &vec : intervals) {
            events.push_back(make_pair(vec[0], 1));
            events.push_back(make_pair(vec[1] + 1, -1));
        }
        events.push_back(make_pair(newInterval[0], 1));
        events.push_back(make_pair(newInterval[1] + 1, -1));
        sort(events.begin(), events.end());
        vector<vector<int>> ans;
        int left;
        int cnt = 0;
        for (pair<int, int> &event : events) {
            if (cnt == 0)
                left = event.first;
            cnt += event.second;
            if (cnt == 0)
                ans.push_back({left, event.first - 1});
        }
        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int k = 0;
        while (k < intervals.size() && intervals[k][1] < newInterval[0])
            res.push_back(intervals[k ++ ]);

        if (k < intervals.size()) {
            newInterval[0] = min(newInterval[0], intervals[k][0]);
            while (k < intervals.size() && intervals[k][0] <= newInterval[1])
                newInterval[1] = max(newInterval[1], intervals[k ++ ][1]);
        }
        res.push_back(newInterval);

        while (k < intervals.size()) res.push_back(intervals[k ++ ]);
        return res;
    }
};
// @lc code=end

