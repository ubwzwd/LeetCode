/*
 * @lc app=leetcode id=3650 lang=cpp
 *
 * [3650] Minimum Cost Path with Edge Reversals
 */
#include <climits>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  vector<int> root;
  int findRoot(int x) {
    if (root[x] != x) {
      root[x] = findRoot(root[x]);
    }
    return root[x];
  }
  void unionNodes(int x, int y) {
    int rootX = findRoot(x);
    int rootY = findRoot(y);
    root[rootX] = rootY;
  }
  bool isConnected(int n, vector<vector<int>> &edges) {
    root = vector<int>(n);
    for (int i = 0; i < n; i++) root[i] = i;
    for (auto &edge : edges) {
      unionNodes(edge[0], edge[1]);
    }
    return findRoot(0) == findRoot(n - 1);
  }

public:
  int minCost(int n, vector<vector<int>> &edges) {
    if (!isConnected(n, edges)) return -1;
    vector<vector<pair<int, int>>> graph(n);
    for (auto &edge : edges) {
      graph[edge[0]].push_back({edge[1], edge[2]});
      graph[edge[1]].push_back({edge[0], edge[2] * 2});
    }
    auto comp = [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.second >= b.second;
    };
    // pair: node, distance to node 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(
        comp);
    vector<int> dists(n, INT_MAX);

    pq.push({0, 0});
    dists[0] = 0;
    // dijkstra
    while (!pq.empty()) {
      auto [node, dist] = pq.top();
      pq.pop();
      if (dist > dists[node])
        continue;
      if (node == n - 1)
        return dist;
      for (auto [nextNode, nextDist] : graph[node]) {
        if (dists[nextNode] < dist + nextDist)
          continue;
        dists[nextNode] = dist + nextDist;
        pq.push({nextNode, dist + nextDist});
      }
    }
    return -1;
  }
};
// @lc code=end
