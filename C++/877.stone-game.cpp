/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  unordered_map<string, int> bestRecord;
  // means, for [i,j], the best result alice can get more than Bob
  int recursiveSolution(vector<int> &piles, int i, int j, bool isAliceTurn) {
    if (i > j)
      return 0;
    string currentKey = to_string(i) + "," + to_string(j);
    if (bestRecord.count(currentKey))
      return bestRecord[currentKey];
    if (isAliceTurn) {
      bestRecord[currentKey] =
          max(piles[i] + recursiveSolution(piles, i + 1, j, ~isAliceTurn),
              piles[j] + recursiveSolution(piles, i, j - 1, ~isAliceTurn));
    } else {
      bestRecord[currentKey] =
          min(-piles[i] + recursiveSolution(piles, i + 1, j, ~isAliceTurn),
              -piles[j] + recursiveSolution(piles, i, j - 1, ~isAliceTurn));
    }
    return bestRecord[currentKey];
  }
  // bool dp(vector<int> &piles) {
  //   int n = piles.size();
  //   int dp[n + 2][n + 2];
  //   for (int size = 1; size <= n; size++) {
  //   }
  // }

  bool mathSolution(vector<int> &piles) { return true; }

public:
  bool stoneGame(vector<int> &piles) {
    return recursiveSolution(piles, 0, piles.size() - 1, true) > 0;
  }
};
// @lc code=end
