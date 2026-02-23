/*
 * @lc app=leetcode id=3010 lang=cpp
 *
 * [3010] Divide an Array Into Subarrays With Minimum Cost I
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
  int minimumCost(vector<int> &nums) {
    auto comp = [](int a, int b) { return a < b; };
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    for (int i = 1; i < nums.size(); i++) {
      if (pq.size() < 2)
        pq.push(nums[i]);
      else {
        if (nums[i] > pq.top())
          continue;
        pq.pop();
        pq.push(nums[i]);
      }
    }
    int cost = nums[0];
    while (!pq.empty()) {
      cost += pq.top();
      pq.pop();
    }
    return cost;
  }
};
// @lc code=end

