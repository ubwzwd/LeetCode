/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.17%)
 * Likes:    2827
 * Dislikes: 350
 * Total Accepted:    483.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<string> keyMap{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void letterCombinationsRec(string digits, int pos, int len, vector<string>& res, string& temp){
        // reach the end of the string
        if(pos == len) {
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < keyMap[digits[pos]-'2'].size(); i++){
            temp.push_back(keyMap[digits[pos]-'2'][i]);
            letterCombinationsRec(digits, pos+1, len, res, temp);
            temp.pop_back();
        }
    }    
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if(len == 0) return vector<string>{};
        vector<string> res;
        int pos = 0;
        string temp = "";
        letterCombinationsRec(digits, pos, len, res, temp);
        return res;
    }
};
// @lc code=end

