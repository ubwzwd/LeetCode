/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> nums;
        int i1 = 0, i2 = 0;
        while(i1 < len1 || i2 < len2){
            if(i2 >= len2 || (i1<len1 && nums1[i1] < nums2[i2])){
                // nums1 is empty or nums1[i1] < nums2[i2]
                nums.push_back(nums1[i1]);
                i1++;
            }
            else{
                nums.push_back(nums2[i2]);
                i2++;
            }
        }
        if((len1+len2)%2 == 0){
            return ((double)nums[(len1+len2)/2]+(double)nums[(len1+len2)/2-1])/2;
        }
        else return (double)nums[(len1+len2)/2];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> nums;
        int i1 = 0, i2 = 0;
        while(i1 < len1 || i2 < len2){
            if(i2 >= len2 || (i1<len1 && nums1[i1] < nums2[i2])){
                // nums1 is empty or nums1[i1] < nums2[i2]
                nums.push_back(nums1[i1]);
                i1++;
            }
            else{
                nums.push_back(nums2[i2]);
                i2++;
            }
        }
        if((len1+len2)%2 == 0){
            return ((double)nums[(len1+len2)/2]+(double)nums[(len1+len2)/2-1])/2;
        }
        else return (double)nums[(len1+len2)/2];
    }
};
