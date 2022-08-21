#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        // f[i][j]: the maximum repeated length of array nums1[0~i] and nums2[0~j]
        vector<vector<int>> f(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            f[0][i] = max(f[0][i], (int) (nums1[0] == nums2[i]));
        for (int i = 0; i < m; i++)
            f[i][0] = max(f[i][0], (int) (nums1[i] == nums2[0]));

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (nums1[i] == nums2[j])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = 0;

        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res = max(res, f[i][j]);
        return res;
    }
};
// @lc code=end

// f[i][j]: Maximum Length of Repeated Subarray ending with A[i - 1] and B[j - 1]
class Solution2 {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        // f[i][j]: the maximum repeated length of array nums1[0~i-1] and nums2[0~j-1]
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));

        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = 0;
                res = max(res, f[i][j]);
            }
        }
        
        return res;
    }
};

// dp with optimized space
class Solution3 {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        // f[i][j]: the maximum repeated length of array nums1[0~i-1] and nums2[0~j-1]
        vector<int> f(n + 1, 0);

        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (nums1[i - 1] == nums2[j - 1]) 
                    f[j] = f[j - 1] + 1;
                else
                    f[j] = 0;
                res = max(res, f[j]);
            }
        }
        
        return res;
    }
};

class Solution4 {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        // f[i][j]: the maximum repeated length of array nums1[0~i-1] and nums2[0~j-1]
        vector<int> f(n + 1, 0);

        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (nums1[i - 1] == nums2[j - 1]) 
                    f[j] = f[j - 1] + 1;
                else
                    f[j] = 0;
                res = max(res, f[j]);
            }
        }
        
        return res;
    }
};

// binary search + string hash
// see: https://www.acwing.com/solution/content/61140/
class Solution5 {
public:
    typedef unsigned long long ULL;
    const int P = 131;
    int m, n;
    // hash1[i]: hash value of substring nums1[0:i], i >= 1 
    vector<ULL> hash1;
    // hash2[i]: hash value of substring nums2[0:i], i >= 1 
    vector<ULL> hash2;
    // p[i]: P^i
    vector<ULL> p;

    int findLength(vector<int> &nums1, vector<int> &nums2) {
        m = nums1.size(), n = nums2.size();
        hash1.resize(m + 1, 0);
        hash2.resize(n + 1, 0);
        for (int i = 1; i <= m; i++) hash1[i] = hash1[i - 1] * P + nums1[i - 1];
        for (int i = 1; i <= n; i++) hash2[i] = hash2[i - 1] * P + nums2[i - 1];
       
        int l = 0, r = min(n, m);
        p.resize(r + 1);
        p[0] = 1;
        for (int i = 1; i <= r; i ++ ) p[i] = p[i - 1] * P;

        // find last num, that 
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        
        return r;
    }
    // calc hash value of the substring s[l~r]
    ULL getHash(vector<ULL>& h, int l, int r) {
        // s[r] - s[l - 1]
        return h[r + 1] - h[l - 1 + 1] * p[r - l + 1];
    }

    // ckeck if there is a substring with length of `len` in both nums1 and nums2
    bool check(int len) {
        unordered_set<ULL> hash;
        for (int i = 0; i + len - 1 < m; i++)
            hash.insert(getHash(hash1, i, i + len - 1));
        for (int i = 0; i + len - 1 < n; i++)
            if (hash.count(getHash(hash2, i, i + len - 1))) return true;
        return false;
    }
};