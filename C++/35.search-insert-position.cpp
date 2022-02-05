/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        while(begin<=end){            
            int mid = (begin+end)>>1;
            cout<< begin << " " << end << " " << mid << endl;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                begin = mid+1;
            else
                end = mid-1;
        }
        // if not found. begin = end + 1, target should be put at position begin
        return begin;
    }
};

// int main(){
//     vector<int> nums{1,3,5,6};
//     Solution s;
//     int res = s.searchInsert(nums, 2);
//     return 0;
// }

