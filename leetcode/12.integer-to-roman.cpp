/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
  string intToRoman(int num) {
    string res;
    for (int i = 0; i < N; i++) {
      while (num >= values[i]) {
        num -= values[i];
        res += reps[i];
      }
    }
    return res;
  }

private:
  static const int N = 13;
  int values[N] = {
      1000,
      900, 500, 400, 100,
      90, 50, 40, 10,
      9, 5, 4, 1};

  string reps[N] = {
      "M",
      "CM", "D", "CD", "C",
      "XC", "L", "XL", "X",
      "IX", "V", "IV", "I"
  };
};
// @lc code=end
