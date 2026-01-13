/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <cstdlib> // 为 srand() 和 rand()
#include <ctime>   // 为 time()
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  int quickSelect(vector<int> &nums, int start, int end, int k) {
    if (start == end) {
      return nums[start];
    }
    // swap(nums, end, start + rand() % (end - start + 1));
    int pivot = nums[end];
    int i = start,
        j = start; // [start, i) < pivot, [i, j) >= pivot, [j, end) unvisited
    while (j < end) {
      if (nums[j] >= pivot)
        j++;
      else {
        swap(nums, i, j);
        i++;
        j++;
      }
    }
    swap(nums, i, end);
    int nLeft = i, nRight = i;
    while (nLeft > start && nums[nLeft] == nums[nLeft - 1]) {
      nLeft--;
    }
    while (nRight < end && nums[nRight] == nums[nRight + 1]) {
      nRight++;
    }
    if (nums.size() - nLeft >= k && nums.size() - nRight <= k) {
      return nums[i];
    }
    if (nums.size() - i > k)
      return quickSelect(nums, i + 1, end, k);
    else
      return quickSelect(nums, start, i - 1, k);
  }

  void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    return;
  }

public:
  int findKthLargest(vector<int> &nums, int k) {
    // srand(time(0));
    return quickSelect(nums, 0, nums.size() - 1, k);
  }
};
// @lc code=end
