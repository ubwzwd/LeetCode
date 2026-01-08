/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  vector<int> root;

  int find(int x) {
    if (root[x] != x) {
      root[x] = find(root[x]);
    }
    return root[x];
  }

  bool unionWithCircleCheck(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
      return false;
    }
    root[rootX] = rootY;
    return true;
  }

public:
  bool validTree(int n, vector<vector<int>> &edges) {
    if (edges.size() != n - 1) {
      return false;
    }
    root = vector<int>(n);
    for (int i = 0; i < n; i++) {
      root[i] = i;
    }
    for (auto &edge : edges) {
      if (!unionWithCircleCheck(edge[0], edge[1])) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
