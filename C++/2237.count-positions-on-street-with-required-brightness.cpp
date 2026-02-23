/*
 * @lc app=leetcode id=2237 lang=cpp
 *
 * [2237] Count Positions on Street With Required Brightness
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int meetRequirement(int n, vector<vector<int>> &lights,
                      vector<int> &requirement) {
    vector<int> brightnessDiff(n);
    for (auto &light : lights) {
      int leftBound = max(0, light[0] - light[1]);
      int rightBound = light[0] + light[1];
      brightnessDiff[leftBound]++;
      if (rightBound < n - 1)
        brightnessDiff[max(leftBound + 1, rightBound + 1)]--;
    }
    for (int i = 1; i < n; i++) {
      brightnessDiff[i] += brightnessDiff[i - 1];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (requirement[i] <= brightnessDiff[i]) {
        res++;
      }
    }
    return res;
  }
};
// @lc code=end
