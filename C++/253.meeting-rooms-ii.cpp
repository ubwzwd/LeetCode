/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    auto comp = [](int a, int b) { return a < b; };
    vector<int> starts, ends;
    for (auto &i : intervals) {
      starts.push_back(i[0]);
      ends.push_back(i[1]);
    }
    sort(starts.begin(), starts.end(), comp);
    sort(ends.begin(), ends.end());
    int i = 0, j = 0, count = 0;
    while ((i < starts.size()) && (j < ends.size())) {
      if (starts[i] < ends[j]) {
        i++;
        count = max(count, i - j);
      } else {
        j++;
      }
    }
    return count;
  }
};
// @lc code=end
