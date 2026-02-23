/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    auto comp = [](const string& x, const string& y) {
      return x + y > y + x;
    };
    vector<string> sorted(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      sorted[i] = to_string(nums[i]);
    }
    sort(sorted.begin(), sorted.end(), comp);
    if (sorted[0] == "0") return "0";
    string res;
    for (auto &s : sorted) {
      res.append(s);
    }
    return res;
  }
};
// @lc code=end

