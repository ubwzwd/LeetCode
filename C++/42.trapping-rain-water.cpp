/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (44.95%)
 * Likes:    4607
 * Dislikes: 81
 * Total Accepted:    361.2K
 * Total Submissions: 800.2K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // use DP
    int trap(vector<int>& height) {
        int len = height.size();
        if(len < 3) return 0;
        vector<int> max_left(len, 0);
        vector<int> max_right(len, 0);
        int res = 0;
        max_left[0] = height[0];        
        for(int i = 1; i < len; i++){
            if(height[i] > max_left[i-1]) max_left[i] = height[i];
            else max_left[i] = max_left[i-1];
        }
        max_right[len-1] = height[len-1];
        for(int i = len-2; i >=0; i--){
            if(height[i] > max_right[i+1]) max_right[i] = height[i];
            else max_right[i] = max_right[i+1];
        }
        for(int i = 0; i < len; i++){
            res += min(max_left[i], max_right[i]) - height[i];
        }
        return res;
    }
};
// @lc code=end

