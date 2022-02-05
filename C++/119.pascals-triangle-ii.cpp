/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (45.36%)
 * Likes:    585
 * Dislikes: 182
 * Total Accepted:    237.8K
 * Total Submissions: 516.2K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return vector<int>{1};
        if(rowIndex == 1) return vector<int>{1,1};
        vector<int> init(rowIndex+1, 0);
        init[0] = 1;
        init[1] = 1;
        vector<int> res = init;
        for(int i = 1; i < rowIndex; i++){
            init = res;
            for(int k = 1; k < rowIndex+1; k++){
                res[k] = init[k]+init[k-1];
            }
        }
        return res;
    }
};
// @lc code=end

