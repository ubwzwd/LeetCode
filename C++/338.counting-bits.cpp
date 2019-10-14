/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (65.76%)
 * Likes:    1676
 * Dislikes: 119
 * Total Accepted:    195.1K
 * Total Submissions: 296.4K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,1]
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: [0,1,1,2,1,2]
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    // vector<int> countBits(int num) {
    //     if(num == 0) return vector<int>{0};
    //     vector<int> res(num+1, 0);
    //     int mod = 0, temp = 0;
    //     for(int i = 1; i <= num; i++){
    //         temp = i;
    //         while(temp>0){
    //             mod = temp>>1;
    //             if(temp - mod*2) res[i]+=1;
    //             temp = mod;
    //         }
    //     }
    //     return res;
    // }

        vector<int> countBits(int num) {
        if(num == 0) return vector<int>{0};
        vector<int> res(num+1, 0);
        for(int i = 1; i <= num; i++){
            // i/2 is 1 bit less than i, with all bits from the highest the same, so just need to consider the lowest bit
            res[i] = res[i>>1] + (i&1);
        }
        return res;
    }
    // these two methods runs for the same time
};
// @lc code=end

