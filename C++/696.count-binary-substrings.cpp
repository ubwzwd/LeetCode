/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 *
 * https://leetcode.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (66.46%)
 * Likes:    4535
 * Dislikes: 960
 * Total Accepted:    335.4K
 * Total Submissions: 482.3K
 * Testcase Example:  '"00110011"'
 *
 * Given a binary string s, return the number of non-empty substrings that have
 * the same number of 0's and 1's, and all the 0's and all the 1's in these
 * substrings are grouped consecutively.
 * 
 * Substrings that occur multiple times are counted the number of times they
 * occur.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive
 * 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 * Notice that some of these substrings repeat and are counted the number of
 * times they occur.
 * Also, "00110011" is not a valid substring because all the 0's (and 1's) are
 * not grouped together.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
 * number of consecutive 1's and 0's.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 * 
 * 
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> continuous;
        int currentCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && s[i] != s[i-1]) {
                continuous.push_back(currentCount);
                currentCount = 0; // reset if element change
            }
            if (s[i] == '0') currentCount--;
            else currentCount++;
        }
        continuous.push_back(currentCount);
        int count = 0;
        for (int i = 1; i < continuous.size(); i++) {
            count += min(abs(continuous[i-1]), abs(continuous[i]));
        }
        return count;
    }
};
// @lc code=end

