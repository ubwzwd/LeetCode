/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <vector>
using namespace std;
class Solution {
private:
  int find(vector<int> &nums1, vector<int> &nums2, int start1, int start2,
           int targetK) {
    if (start1 >= nums1.size()) {
      return nums2[start2 + targetK - 1];
    }
    if (start2 >= nums2.size()) {
      return nums1[start1 + targetK - 1];
    }
    if (targetK == 1) {
      return min(nums1[start1], nums2[start2]);
    }
    // every time we find targetK/2 th elements
    int mid1 = start1 + targetK / 2 - 1;
    int mid2 = start2 + targetK / 2 - 1;

    // first case: exclude part of nums2
    if ((mid1 >= nums1.size()) ||
        (mid2 < nums2.size() && nums1[mid1] > nums2[mid2])) {
      return find(nums1, nums2, start1, mid2 + 1, targetK - targetK / 2);
    } else {
      return find(nums1, nums2, mid1 + 1, start2, targetK - targetK / 2);
    }
  }

public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    // find the (len1 + len2 + 1)/2 th element in these 2 array
    int targetK = (len1 + len2 + 1) /
                  2; // if len1 + len2 is even, we need target + target+1
    if ((len1 + len2) % 2 == 1) {
      return double(find(nums1, nums2, 0, 0, targetK));
    } else {
      return (double(find(nums1, nums2, 0, 0, targetK) +
                     find(nums1, nums2, 0, 0, targetK + 1))) /
             2;
    }
  }
};