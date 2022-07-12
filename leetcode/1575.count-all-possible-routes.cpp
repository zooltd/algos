#include <vector>
#include <cmath>
using namespace std;
/*
 * @lc app=leetcode id=1575 lang=cpp
 *
 * [1575] Count All Possible Routes
 */

// @lc code=start
/**
 * @brief https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247485319&idx=1&sn=95a3dc9c97ca57185de792ca70924afe&chksm=fd9cac98caeb258ebea466f59378670a90af1cb3015ae70922e1d04ac711a5b8d8d853ac5e7d&scene=178&cur_album_id=1773144264147812354#rd
 */
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> f(n, vector<int>(fuel + 1, 0));
        for (int i = 0; i <= fuel; i++) f[finish][i] = 1;
        // f[i][fuel] = f[i][fuel] + f[k][fuel - need]
        for (int left = 0; left <= fuel; left++)
            for (int i = 0; i < n; i++)
                for (int k = 0; k < n; k++) {
                    if (i != k) {
                        int need = abs(locations[i] - locations[k]);
                        if (left >= need) {
                            f[i][left] += f[k][left - need];
                            f[i][left] %= MOD;
                        }
                    }
                }
        return f[start][fuel];
    }

private:
    const int MOD = 1e9 + 7;
};

/**
 * @brief https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247485297&idx=1&sn=5ee4ce31c42d368af0653f60aa263c82&chksm=fd9cac6ecaeb25787e6da90423c5467e1679da0a8aaf1a3445475199a8f148d8629e851fea57&scene=178&cur_album_id=1773144264147812354#rd
 */
class Solution2 {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        cache.resize(n, vector<int>(fuel + 1, -1));
        vector<vector<int>> cache(n, vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel);
    }

    int dfs(vector<int>& locations, int u, int finish, int fuel) {
        if (cache[u][fuel] != -1)
            return cache[u][fuel];
        
        int need = abs(locations[u] - locations[finish]);
        if (need > fuel) {
            cache[u][fuel] = 0;
            return 0;
        }

        int n = locations.size();
        int sum = u == finish ? 1 : 0;
        for (int i = 0; i < n; i++)
            if (i != u) {
                int need = abs(locations[i] - locations[u]);
                if (fuel >= need) {
                    sum += dfs(locations, i, finish, fuel - need);
                    sum %= MOD;
                }
            }
        cache[u][fuel] = sum;
        return sum;
    }

private:
    // cache[i][fuel]: start from i, with remaining fuel, how many routes to stop
    vector<vector<int>> cache;
    const int MOD = 1e9 + 7;
};

class Solution1 {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        cache.resize(n, vector<int>(fuel + 1, -1));
        vector<vector<int>> cache(n, vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel);
    }

    /**
     * @brief 
     * 
     * @param locations 
     * @param u current point
     * @param finish target point
     * @param fuel remaining fuel
     * @return int start from u, with remaining fuel, how many routes to finish point
     */
    int dfs(vector<int>& locations, int u, int finish, int fuel) {
        if (cache[u][fuel] != -1)
            return cache[u][fuel];
        
        int n = locations.size();

        // base case 1: run out of fuel, but cannot make it to finish point
        if (fuel == 0 && u != finish) {
            cache[u][fuel] = 0;
            return 0;
        }

        // base case 2: fuel != 0 but cannot move to any other points
        bool hasNext = false;
        for (int i = 0; i < n; i++)
            if (i != u) {
                int need = abs(locations[u] - locations[i]);    
                if (fuel >= need) {
                    hasNext = true;
                    break;
                }
            }
        if (fuel != 0 && !hasNext) {
            int returnVal = cache[u][fuel] = u == finish ? 1 : 0;
            return returnVal;
        }

        // base case 3: fuel != 0 && can move to some points
        int sum = u == finish ? 1 : 0;
        for (int i = 0; i < n; i++)
            if (i != u) {
                int need = abs(locations[i] - locations[u]);
                if (fuel >= need) {
                    sum += dfs(locations, i, finish, fuel - need);
                    sum %= MOD;
                }
            }
        cache[u][fuel] = sum;
        return sum;
    }

private:
    // cache[i][fuel]: start from i, with remaining fuel, how many routes to stop
    vector<vector<int>> cache;
    const int MOD = 1e9 + 7;
};
// @lc code=end

