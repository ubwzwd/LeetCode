/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.12%)
 * Likes:    2581
 * Dislikes: 115
 * Total Accepted:    247.9K
 * Total Submissions: 821.7K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int max_product = nums[0];
        int temp_min = nums[0], temp_max = nums[0];
        for(int i = 1; i < len; i++){
            if(nums[i] < 0){
                int temp_max_temp = temp_max;
                temp_max = max(nums[i], temp_min*nums[i]);
                temp_min = min(nums[i], temp_max_temp*nums[i]);
            }
            else{
                temp_max = max(nums[i], temp_max*nums[i]);
                temp_min = min(nums[i], temp_min*nums[i]);
            }
            max_product = max(max_product, temp_max);
        }
        return max_product;
    }
};
// @lc code=end

