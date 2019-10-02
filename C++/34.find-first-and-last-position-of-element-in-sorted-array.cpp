/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid = 0;
        while(left<=right){
            mid = (left+right)>>1;
            if(target == nums[mid]){
                int front = mid, back = mid;
                while(front > 0 && nums[front] == nums[front-1])
                    front--;
                while(back < nums.size()-1 && nums[back] == nums[back+1])
                    back++;
                return vector<int>{front, back};
            }
            else if(target>nums[mid]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return vector<int>{-1,-1};
    }
};

