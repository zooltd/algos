#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start
class Solution {
public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    unordered_set<int> blockers;
    for (auto &vec : obstacles)
      blockers.insert(vec2hashable(vec[0], vec[1]));

    // direction array
    //           N  E  S   W
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int x = 0, y = 0;
    int dir = 0; // N
    int ans = 0;

    for (int cmd : commands) {
      if (cmd > 0) {
        for (int i = 0; i < cmd; i++) {
          int next_x = x + dx[dir];
          int next_y = y + dy[dir];

          if (blockers.find(vec2hashable(next_x, next_y)) != blockers.end())
            break;

          x = next_x;
          y = next_y;
          ans = max(ans, x * x + y * y);
        }
      } else if (cmd == -1)
        dir = (dir + 1) % 4;
      else
        dir = (dir - 1 + 4) % 4;
    }
    return ans;
  }

private:
  int vec2hashable(int x, int y) { return (x + 30000) * 60000ll + y + 30000; }
  // string vec2hashable(int x, int y) {
  //   return to_string(x) + "," + to_string(y);
  // }
};
// @lc code=end
