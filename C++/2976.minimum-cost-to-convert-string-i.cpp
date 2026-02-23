/*
 * @lc app=leetcode id=2976 lang=cpp
 *
 * [2976] Minimum Cost to Convert String I
 */
#include <climits>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  long long minimumCostFailedDP(string source, string target,
                                vector<char> &original, vector<char> &changed,
                                vector<int> &cost) {
    unordered_map<char, vector<pair<char, int>>> distances;
    for (int i = 0; i < original.size(); i++) {
      distances[original[i]].push_back({changed[i], cost[i]});
    }
    int totalCost = 0;
    vector<vector<long>> dp(26, vector<long>(26, INT_MAX));
    for (int i = 0; i < source.size(); i++) {
      // find the diff element first
      if (source[i] == target[i])
        continue;

      vector<long> &curDP = dp[source[i] - 'a'];
      // if we have calculated for source[i]
      if (curDP[source[i] - 'a'] == 0) {
        if (curDP[target[i] - 'a'] >= INT_MAX)
          return -1;
      }
      curDP[source[i] - 'a'] = 0;
      queue<pair<char, int>> q; // [letter, cost]
      q.push({source[i], 0});
      while (!q.empty()) {
        auto [curChar, cost] = q.front();
        q.pop();
        // find the next sources
        if (distances.count(curChar) > 0) {
          for (auto [nextCur, incCost] : distances[curChar]) {
            if (cost + incCost < curDP[nextCur - 'a']) {
              // need update here
              curDP[nextCur - 'a'] = cost + incCost;
              q.push({nextCur, curDP[nextCur - 'a']});
            }
          }
        }
      }
      if (curDP[target[i] - 'a'] >= INT_MAX)
        return -1;
      totalCost += curDP[target[i] - 'a'];
    }
    return totalCost;
  }

  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {
    vector<vector<long long>> closest(26, vector<long long>(26, LONG_LONG_MAX));
    for (int i = 0; i < 26; i++) {
      closest[i][i] = 0;
    }
    for (int i = 0; i < original.size(); i++) {
      closest[original[i] - 'a'][changed[i] - 'a'] =
          min(closest[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
    }
    for (int k = 0; k < 26; k++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          if (closest[i][k] == LONG_LONG_MAX || closest[k][j] == LONG_LONG_MAX)
            continue;
          closest[i][j] = min(closest[i][j], closest[i][k] + closest[k][j]);
        }
      }
    }
    long long totalCost = 0;
    for (int i = 0; i < source.size(); i++) {
      if (source[i] == target[i])
        continue;
      if (closest[source[i] - 'a'][target[i] - 'a'] == LONG_LONG_MAX)
        return -1;
      totalCost += closest[source[i] - 'a'][target[i] - 'a'];
    }
    return totalCost;
  }
};

// @lc code=end
