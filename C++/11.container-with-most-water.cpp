/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (46.92%)
 * Likes:    4259
 * Dislikes: 490
 * Total Accepted:    488.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len <= 1) return 0;
        int left = 0, right = len-1, temp_area = 0, area = 0;
        while(left<right){
            temp_area = min(height[left], height[right]) * (right - left);
            area = (temp_area>area)? temp_area : area;
            if(height[right] > height[left]) left++;
            else right--;
        }
        return area;
    }
};
// @lc code=end

