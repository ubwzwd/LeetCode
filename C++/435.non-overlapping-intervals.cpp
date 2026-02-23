/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      auto comp = [](const vector<int> &x, const vector<int> &y) {
        return x[1] < y[1];
      };
      sort(intervals.begin(), intervals.end(), comp);
      int lastEnd = INT_MIN;
      int count = 0;
      for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][0] < lastEnd) { // drop this interval
          count++;
        } else {
          lastEnd = intervals[i][1];
        }
      }
      return count;
    }
};
// @lc code=end

