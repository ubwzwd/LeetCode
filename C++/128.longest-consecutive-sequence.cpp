/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  unordered_map<int, int> root;
  void unionSet(int x, int y) {
    int rootX = findRoot(x);
    int rootY = findRoot(y);
    if (rootX != rootY) {
      root[rootX] = rootY;
    }
  }
  int findRoot(int x) {
    if (root[x] != x) {
      root[x] = findRoot(root[x]);
    }
    return root[x];
  }

public:
  int longestConsecutive(vector<int> &nums) {
    for (auto num : nums) {
      root.insert({num, num});
    }
    for (auto num : nums) {
      if (root.count(num - 1))
        unionSet(num, num - 1);
      if (root.count(num + 1))
        unionSet(num, num + 1);
    }
    unordered_map<int, int> countMap;
    for (auto [num, root] : root) {
      int actualRoot = findRoot(root);
      if (countMap.count(actualRoot))
        countMap[actualRoot]++;
      else
        countMap.insert({actualRoot, 1});
    }
    int maxCount = 0;
    for (auto [root, count] : countMap) {
      maxCount = max(maxCount, count);
    }
    return maxCount;
  }
};
// @lc code=end
