/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    // shortestFromSource[i][j] means the shortest distance from src to i, with
    // j stops
    vector<vector<int>> shortestFromSource(n, vector<int>(k + 2, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(k + 2));
    vector<vector<pair<int, int>>> graph(n);
    for (auto &f : flights) {
      graph[f[0]].push_back({f[1], f[2]});
    }
    queue<pair<int, int>> q; // pair<node, number of stops spent>
    q.push({src, 0});
    visited[src][0] = true;
    shortestFromSource[src][0] = 0;
    while (!q.empty()) {
      auto [node, step] = q.front();
      q.pop();
      if (step > k)
        continue;
      // visit node's neighbour and update the distance
      for (int i = 0; i < graph[node].size(); i++) {
        auto [dest, dis] = graph[node][i];
        if (dis == 0)
          continue;
        shortestFromSource[dest][step + 1] =
            min(shortestFromSource[dest][step + 1],
                shortestFromSource[node][step] + dis);
        if (!visited[dest][step + 1]) {
          q.push({dest, step + 1});
          visited[dest][step + 1] = true;
        }
      }
    }
    int minDis = INT_MAX;
    for (auto dis : shortestFromSource[dst]) {
      minDis = min(minDis, dis);
    }
    return minDis == INT_MAX ? -1 : minDis;
  }
};
// @lc code=end
