/*
 * @lc app=leetcode id=256 lang=cpp
 *
 * [256] Paint House
 *
 * https://leetcode.com/problems/paint-house/description/
 *
 * algorithms
 * Easy (50.12%)
 * Likes:    471
 * Dislikes: 48
 * Total Accepted:    63.8K
 * Total Submissions: 127K
 * Testcase Example:  '[[17,2,17],[16,16,5],[14,3,19]]'
 *
 * There are a row of n houses, each house can be painted with one of the three
 * colors: red, blue or green. The cost of painting each house with a certain
 * color is different. You have to paint all the houses such that no two
 * adjacent houses have the same color.
 * 
 * The cost of painting each house with a certain color is represented by a n x
 * 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with
 * color red; costs[1][2] is the cost of painting house 1 with color green, and
 * so on... Find the minimum cost to paint all houses.
 * 
 * Note:
 * All costs are positive integers.
 * 
 * Example:
 * 
 * 
 * Input: [[17,2,17],[16,16,5],[14,3,19]]
 * Output: 10
 * Explanation: Paint house 0 into blue, paint house 1 into green, paint house
 * 2 into blue. 
 * Minimum cost: 2 + 5 + 3 = 10.
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int house_num = costs.size();
        if(house_num == 0) return 0;
        vector<int> pre_total{costs[0][0], costs[0][1], costs[0][2]};
        vector<int> cur_total(pre_total);
        for(int i = 1; i < house_num; i++){
            for(int j = 0; j < 3; j++){
                pre_total[j] = cur_total[j];
            }
            cur_total[0] = min(pre_total[1], pre_total[2]) + costs[i][0];           
            cur_total[1] = min(pre_total[0], pre_total[2]) + costs[i][1];           
            cur_total[2] = min(pre_total[1], pre_total[0]) + costs[i][2];
        }
        return min(cur_total[0], min(cur_total[1], cur_total[2]));
    }
};
// @lc code=end

