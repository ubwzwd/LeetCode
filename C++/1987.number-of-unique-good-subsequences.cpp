/*
 * @lc app=leetcode id=1987 lang=cpp
 *
 * [1987] Number of Unique Good Subsequences
 */
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
private:
  void recursionSolution(string binary, int index, string &cur,
                         unordered_set<string> &stringSet) {
    if (index == binary.size())
      return;

    // remove leading 0
    if (cur.size() >= 1 && cur[0] == '0') {
      return;
    }

    // there are 2 options: take this element, or ignore this element
    recursionSolution(
        binary, index + 1, cur,
        stringSet); // we ignore current element. cur should already be in set,
                    // so just go next recursion
    cur.push_back(binary[index]);
    if (stringSet.count(cur) == 0)
      stringSet.insert(cur);
    recursionSolution(binary, index + 1, cur, stringSet);
    cur.pop_back();
    return;
  }

  int dpSolution(string binary) {
    int dp0 = 0; // the number of subsequence ended by 0
    int dp1 = 0; // the number of subsequence ended by 1
  }

public:
  int numberOfUniqueGoodSubsequences(string binary) {
    unordered_set<string> resultSet;
    string cur;
    recursionSolution(binary, 0, cur, resultSet);
    // for (const auto &i : resultSet) {
    //   cout << i << endl;
    // }
    return resultSet.size() % (10 ^ 9 + 7);
  }
};
// @lc code=end
