/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  unordered_set<string> failedPattern;
  bool bruteforce(string &bottom,
                  unordered_map<string, vector<char>> &allowedMap,
                  string &nextBottom, int curIndex) {
    if (curIndex == bottom.size() - 1) { // cur layer is done
      if (nextBottom.size() == 1)        // nextBottom is top
        return true;
      else {
        string n = "";
        return bruteforce(nextBottom, allowedMap, n, 0);
      }
    }

    if (failedPattern.count(nextBottom))
      return false;
    // try every possible on current index
    string pattern = bottom.substr(curIndex, 2);
    for (auto c : allowedMap[pattern]) {
      nextBottom.push_back(c);
      if (bruteforce(bottom, allowedMap, nextBottom, curIndex + 1))
        return true;
      nextBottom.pop_back();
    }
    failedPattern.insert(bottom);
    return false;
  }

public:
  bool pyramidTransition(string bottom, vector<string> &allowed) {
    if (bottom.size() == 1)
      return true;
    unordered_map<string, vector<char>> allowedMap;
    for (string &s : allowed) {
      allowedMap[s.substr(0, 2)].push_back(s[2]);
    }
    string n = "";
    return bruteforce(bottom, allowedMap, n, 0);
  }
};
// @lc code=end
