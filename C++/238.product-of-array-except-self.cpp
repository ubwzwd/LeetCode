/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (56.78%)
 * Likes:    2895
 * Dislikes: 249
 * Total Accepted:    320.6K
 * Total Submissions: 562.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> res(nums.size(), 0);
    //     vector<int> left_product(nums.size(), 1);
    //     vector<int> right_product(nums.size(), 1);
    //     for(int i = 1; i < nums.size(); i++){
    //         left_product[i] = left_product[i-1] * nums[i-1];
    //     }
    //     for(int i = nums.size()-2; i >= 0; i--){
    //         right_product[i] = right_product[i+1] * nums[i+1];
    //     }
    //     for(int i = 0; i < nums.size(); i++){
    //         res[i] = left_product[i]*right_product[i];
    //     }
    //     return res;
    // }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product(nums.size(), 1);
        int R = 1;
        for(int i = 1; i < nums.size(); i++){
            product[i] = product[i-1] * nums[i-1];
        }
        for(int i = nums.size()-2; i >= 0; i--){
            R = R*nums[i+1];
            product[i] = product[i] * R;
        }
        return product;
    }
};
// @lc code=end

