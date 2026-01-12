/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        // scan from left to right, carries the left boundary
        int left = 0, right = height.size() - 1, leftH = height[0], rightH = height[height.size() - 1];
        while (left < right - 1)
        {
            if (leftH < rightH)
            {
                left++;
                if (height[left] < leftH)
                {
                    res += leftH - height[left];
                }
                else
                {
                    leftH = height[left];
                }
            }
            else
            {
                right--;
                if (height[right] < rightH)
                {
                    res += rightH - height[right];
                }
                else
                {
                    rightH = height[right];
                }
            }
        }
        return res;
    }
};
// @lc code=end
