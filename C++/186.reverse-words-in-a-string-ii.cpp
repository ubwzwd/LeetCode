/*
 * @lc app=leetcode id=186 lang=cpp
 *
 * [186] Reverse Words in a String II
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-ii/description/
 *
 * algorithms
 * Medium (39.52%)
 * Likes:    342
 * Dislikes: 88
 * Total Accepted:    75.8K
 * Total Submissions: 187.6K
 * Testcase Example:  '["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]'
 *
 * Given an input string , reverse the string word by word. 
 * 
 * Example:
 * 
 * 
 * Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 * Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 * 
 * Note: 
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * The input string does not contain leading or trailing spaces.
 * The words are always separated by a single space.
 * 
 * 
 * Follow up: Could you do it in-place without allocating extra space?
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    template <typename T>
    void swap(T& a, T& b){
        T temp = a;
        a = b;
        b = temp;
    }
public:
    void reverseWords(vector<char>& s) {
        int len = s.size();
        if(len<2) return;
        for(int i = 0; i < len/2; i++){
            swap(s[i], s[len-1-i]);
        }
        int left = 0, right =0;
        while(left<len && right<len){
            right = left;
            while(right < len && s[right] != ' ') right++;
            for(int i = left; i < (right+left)/2; i++){
                swap(s[i], s[left+right-i-1]);
            }
            left = right+1;
        }
    }
};
// @lc code=end

