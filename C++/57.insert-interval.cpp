/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int startIndex = -1;
    int endIndex = -1;
    for (int i = 0; i < intervals.size(); i++) {
      // meaning new interval can be inserted after startIndex
      if (intervals[i][0] <= newInterval[0])
        startIndex = i; // this can be optimised to log(n) with binary search
                        // meaning newInterval can merge the intervals until i
      if (intervals[i][0] <= newInterval[1])
        endIndex = i;
    }
    vector<vector<int>> res;

    // if there's no interval between new and existing lists, and the
    // newInterval is either in the beginning or in the end startIndex = -1
    // && endIndex = -1
    if (startIndex == -1 && endIndex == -1) {
      // need to check whether it's in the beginning or in the end
      // meaning at the beginning
      res.push_back(newInterval);
    }

    // when interval is at the beginning
    // startIndex = -1

    // when interval is at the end
    // endIndex = -1

    // meaning in the original intervals, the element from startIndex to
    // endIndex will need to be merged with newInterval
    int i = 0;
    while (i < intervals.size()) {
      if (i < startIndex || i > endIndex) {
        res.push_back(intervals[i]);
        i++;
      } else {
        // now i is startIndex
        if (intervals[i][1] < newInterval[0]) {
          res.push_back(intervals[i]);
          res.push_back(newInterval);
          i++;
        } else if (intervals[i][0] > newInterval[1]) {
          res.push_back(newInterval);
          res.push_back(intervals[i]);
          i++;
        } else {
          int newStart = newInterval[0];
          int newEnd = newInterval[1];
          if (startIndex >= 0) {
            newStart = min(intervals[startIndex][0], newStart);
          }
          if (endIndex >= 0) {
            newEnd = max(intervals[endIndex][1], newEnd);
          }
          // if startIndex = -1, endIndex = -1, we will never enter
          // this position
          vector<int> nI{min(intervals[startIndex][0], newInterval[0]),
                         max(intervals[endIndex][1], newInterval[1])};
          res.push_back(nI);
          i = max(startIndex + 1, endIndex + 1);
        }
      }
    }

    return res;
  }
};

// @lc code=end

