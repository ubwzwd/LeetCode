/*
 * @lc app=leetcode id=2381 lang=cpp
 *
 * [2381] Shifting Letters II
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>> &shifts) {
    int n = s.size();
    vector<int> diff(s.size() + 1);
    for (auto &shift : shifts) {
      if (shift[2] == 0) {
        diff[shift[0]]--;
        diff[shift[1] + 1]++;
      } else {
        diff[shift[0]]++;
        diff[shift[1] + 1]--;
      }
    }
    for (int i = 1; i < n + 1; i++) {
      diff[i] += diff[i - 1];
    }
    for (int i = 0; i < s.size(); i++) {
      int shift = ((diff[i] % 26) + 26) % 26;
      s[i] = 'a' + (s[i] - 'a' + shift) % 26;
    }
    return s;
  }
};
// @lc code=end
