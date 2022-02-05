/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 *
 * https://leetcode.com/problems/decode-ways-ii/description/
 *
 * algorithms
 * Hard (25.60%)
 * Likes:    307
 * Dislikes: 414
 * Total Accepted:    24.7K
 * Total Submissions: 96.4K
 * Testcase Example:  '"*"'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping way:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Beyond that, now the encoded string can also contain the character '*',
 * which can be treated as one of the numbers from 1 to 9.
 * 
 * 
 * 
 * 
 * Given the encoded message containing digits and the character '*', return
 * the total number of ways to decode it.
 * 
 * 
 * 
 * Also, since the answer may be very large, you should return the output mod
 * 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * Input: "*"
 * Output: 9
 * Explanation: The encoded message can be decoded to the string: "A", "B",
 * "C", "D", "E", "F", "G", "H", "I".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1*"
 * Output: 9 + 9 = 18
 * 
 * 
 * 
 * Note:
 * 
 * The length of the input string will fit in range [1, 10^5].
 * The input string will only contain the character '*' and digits '0' - '9'.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
    int isValid(const char& a){
        if(a != '*')
            return a!='0';
        else return 9;
    }

    int isValid(const char& a, const char& b){
        if(a != '*' && b != '*')
            return a == '1' || (a == '2' && b <= '6');
        else if(a == '*' && b != '*'){
            // a can only be 1 or 2
            return 1 + (b <= '6');
        }
        else if(a != '*' && b == '*'){
            // a != '*' && b == '*'
            return (9*(a == '1')) + (6*(a == '2'));
        }
        else{
            // a == '*' == b
            return 15;
        }
    }
public:
    int numDecodings(string s) {
        // the same as step 1 or 2
        int len = s.size();
        if(len == 0 || !isValid(s[0])) return 0;
        if(len == 1 && isValid(s[0])) return isValid(s[0]);
        vector<long> dp(len, 0);
        dp[0] = isValid(s[0]);
        if(isValid(s[0], s[1])) dp[1] = isValid(s[0], s[1]);
        if(isValid(s[1])) dp[1]+= dp[0]*isValid(s[1]);
        for(int i = 2; i < len; i++){
            // if(isValid(s[i])) dp[i] += (dp[i-1] + isValid(s[i]) - 1);
            dp[i] += (dp[i-1] * isValid(s[i]) );
            // if(isValid(s[i-1], s[i])) dp[i] += (dp[i-2] + isValid(s[i]) - 1);
            dp[i] += (dp[i-2] * isValid(s[i-1], s[i]) );
            dp[i] = dp[i]%1000000007;
        }
        return dp[len-1];
    }
};
// @lc code=end

