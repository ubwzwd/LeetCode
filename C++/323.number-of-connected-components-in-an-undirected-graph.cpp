/*
 * @lc app=leetcode id=323 lang=cpp
 *
 * [323] Number of Connected Components in an Undirected Graph
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  vector<int> root;
  int find(int x) { // O(n) worst, O(1) average
    if (root[x] != x) {
      root[x] = find(root[x]);
    }
    return root[x];
  }
  void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      root[rootX] = rootY;
    }
    return;
  }

public:
  int countComponents(int n, vector<vector<int>> &edges) {
    root = vector<int>(n); // O(n)
    for (int i = 0; i < n; i++) {
      root[i] = i;
    }
    for (auto &edge : edges) {
      unionSet(edge[0], edge[1]);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (i == root[i]) {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
