/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
private:
  int calculateRect(vector<int>& heights, int currentIndex,
                    stack<int> &s) {
    int popEle = heights[s.top()];
    s.pop();
    int startIndex = 0;
    if (!s.empty())
      startIndex = s.top() + 1;
    return (currentIndex - startIndex) * popEle;
  }
public:
  int largestRectangleArea(vector<int> &heights) {
    // use stack
    stack<int> s;
    int maxRect = 0;
    for (int i = 0; i < heights.size(); i++) {
      // check if current value is less than existing
      while (!s.empty() && heights[i] < heights[s.top()]) {
        maxRect = max(maxRect, calculateRect(heights, i, s));
      }
      s.push(i);
    }
    while (!s.empty()) {
      maxRect = max(maxRect, calculateRect(heights, (int)heights.size(), s));
    }
    return maxRect;
  }
};

// @lc code=end

