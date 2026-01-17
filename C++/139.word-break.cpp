/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (37.82%)
 * Likes:    3289
 * Dislikes: 174
 * Total Accepted:    448.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Note:
 *
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 *
 *
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
  unordered_map<string, bool> map;

public:
  bool wordBreak(string s, vector<string> &wordDict) {
    // unordered_set<string> dict(wordDict.begin(), wordDict.end());
    // return wordBreakRec(s, dict);
    return dpBottomUp(s, wordDict);
  }

  bool wordBreakRec(const string &s, const unordered_set<string> &dict) {
    if (dict.count(s))
      return true;
    if (map.count(s))
      return map[s];

    // else, break s into 2 parts and check if both parts can be done
    // [0. i), [i, s.size() - 1]
    for (int i = 1; i < s.size(); i++) {
      const string left = s.substr(0, i);
      const string right = s.substr(i);
      if (wordBreakRec(left, dict) && wordBreakRec(right, dict)) {
        map[s] = true;
        return true;
      }
    }
    map[s] = false;
    return false;
  }

  bool dpBottomUp(string s, const vector<string> &dict) {
    vector<bool> dp(s.size()); // dp[i] represents substring[0, i] can be broken
                               // into dict or not. s[-1]== true as empty string
                               // can be seen as always elegible
    for (int i = 0; i < s.size(); i++) {
      for (auto &word : dict) {
        int prevI = i - word.size();
        if (prevI == -1 || (prevI >= 0 && dp[prevI])) {
          // check if substr == word
          if (s.substr(prevI + 1, word.size()) == word) {
            dp[i] = true;
            break;
          }
        }
      }
    }
    return dp[s.size() - 1];
  }
};
// @lc code=end
