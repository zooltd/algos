#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// class Solution {
// public:
//   int strStr(string haystack, string needle) {
//     for (int i = 0; i + needle.size() <= haystack.size(); i++) {
//       bool isExist = true;
//       for (int j = 0; j < needle.size(); j++) {
//         if (haystack[i + j] != needle[j]) {
//           isExist = false;
//           break;
//         }
//       }
//       if (isExist) {
//         return i;
//       }
//     }
//     return -1;
//   }
// };

// @lc code=start
/* Rabin-Karp Algo */
class Solution {
public:
  const int BASE = 10e6;
  /*         source: abcde, target: cde        */
  int strStr(string source, string target) {
    int m = target.length();
    if (m == 0)
      return 0;
    /* 31^m */
    int power = 1;
    for (int i = 0; i < m; i++)
      power = (power * 31) % BASE;

    int target_hash_code = 0;
    for (const char ch : target)
      target_hash_code = (target_hash_code * 31 + ch) % BASE;

    int source_hash_code = 0;
    for (int i = 0; i < source.length(); i++) {
      /* abc + d */
      source_hash_code = (source_hash_code * 31 + source[i]) % BASE;

      if (i < m - 1)
        continue;

      /* abcd - a */
      if (i >= m) {
        source_hash_code = source_hash_code - (power * source[i - m]) % BASE;
        if (source_hash_code < 0) {
          source_hash_code += BASE;
        }
      }

      if (source_hash_code == target_hash_code) {
        if (source.substr(i - m + 1, m) == target)
          return i - m + 1;
      }
    }
    return -1;
  }
};
// @lc code=end
