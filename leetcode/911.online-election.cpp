#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=911 lang=cpp
 *
 * [911] Online Election
 */

// @lc code=start
class TopVotedCandidate {
public:
  TopVotedCandidate(vector<int> &persons, vector<int> &times) {
    n = times.size();
    points = std::move(times);
    winners.resize(n);
    vector<int> cnt(n + 1, 0);
    /* last winner */
    int winner = -1;
    /* last winner's votes */
    int maxNum = -1;
    for (int i = 0; i < n; ++i) {
      cnt[persons[i]]++;
      if (cnt[persons[i]] >= maxNum) {
        maxNum = cnt[persons[i]];
        winner = persons[i];
      }
      winners[i] = winner;
    }
  }

  int q(int t) {
    int left = 0, right = n - 1;
    int mid;
    /* the last num <= t */
    while (left < right) {
      mid = left + (right - left + 1) / 2;
      if (points[mid] <= t)
        left = mid;
      else
        right = mid - 1;
    }
    return winners[right];
  }

private:
  int n;
  /* time points */
  vector<int> points;
  /* winners at each time point */
  vector<int> winners;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end
