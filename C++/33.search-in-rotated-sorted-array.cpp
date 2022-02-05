/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        while(begin<= end){
            int mid = (begin+end)>>1;
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid]){
                // the vector is increasing continiously between begin and mid
                if(nums[begin] <= nums[mid]){
                    // target is between begin and mid
                    if(target >= nums[begin])
                        end = mid-1;
                    // target < nums[begin], so target is in the second half
                    else begin = mid+1;
                }
                // there is rotation between begin and mid, then the minimum of this vector should exist between begin and mid
                else
                {
                    end = mid-1;
                }    
            }
            //target > nums[mid]
            else{
                // vector is increasing between mid and end
                if(nums[mid] <= nums[end]){
                    if(target <= nums[end]){
                        begin = mid+1;
                    }
                    else end = mid-1;
                }
                // there is rotation between mid and end
                else{
                    // target is between mid and end, because the maximum is between mid and end
                    begin = mid+1;
                }
            }
        }
        return -1;
    }
};

// int main(){
//     vector<int> nums{1,3};
//     Solution s;
//     int res = s.search(nums, 3);
//     cout<<res;
//     return 0;
// }
