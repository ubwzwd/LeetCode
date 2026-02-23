/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int left = 0;
    int right = letters.size();
    while (left < right) {
      int mid = (left + right) / 2;
      if (letters[mid] - target <= 0)
        left = mid + 1;
      else
        right = mid;
    }
    if (left >= letters.size() || letters[left] - target == 0)
      return letters[0];
    return letters[left];
  }
};
// @lc code=end

