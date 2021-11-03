#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter {
public:
  Twitter() {
    time = 0;
    following.clear();
    tweets.clear();
  }

  void postTweet(int userId, int tweetId) {
    tweets[userId].emplace_back(make_pair(time++, tweetId));
  }

  vector<int> getNewsFeed(int userId) {
    auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {
      return a.first < b.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);

    for (pair<int, int> &tweet : tweets[userId])
      pq.push(tweet);

    for (auto &&following_user : following[userId])
      for (pair<int, int> &tweet : tweets[following_user])
        pq.push(tweet);

    vector<int> res;
    res.reserve(10);
    int cnt = 0;
    while (cnt < 10 && !pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
      cnt++;
    }
    return res;
  }

  void follow(int followerId, int followeeId) {
    if (followerId != followeeId)
      following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    following[followerId].erase(followeeId);
  }

private:
  int time;
  unordered_map<int, unordered_set<int>> following;
  unordered_map<int, vector<pair<int, int>>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
