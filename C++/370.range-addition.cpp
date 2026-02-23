/*
 * @lc app=leetcode id=370 lang=cpp
 *
 * [370] Range Addition
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    vector<int> inc(length);
    for (auto &update : updates) {
      int start = update[0];
      int end = update[1];
      int diff = update[2];
      inc[start] += diff;
      if (end < length - 1)
        inc[end + 1] -= diff;
    }
    vector<int> res(length);
    res[0] = inc[0];
    for (int i = 1; i < length; i++) {
      res[i] = res[i - 1] + inc[i];
    }
    return res;
  }
};
// @lc code=end
