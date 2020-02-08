/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (42.11%)
 * Likes:    2329
 * Dislikes: 65
 * Total Accepted:    256.4K
 * Total Submissions: 606.5K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        if(n==0) return false;
        int left = 0, mid = m/2, right = m-1;
        while(left < right){
            mid = left+(right-left)/2;
            if(matrix[mid][0] < target){
                left = mid+1;
            } else if(matrix[mid][0] > target){
                right = mid;
            } else{
                return true;
            }
        }
        // stop means that this whole row is all greater than target
        int stop = min(m, left+1);
        left = 0;
        right = m-1;
        while(left < right){
            mid = left+(right-left)/2;
            if(matrix[mid][n-1] < target){
                left = mid+1;
            } else if(matrix[mid][n-1] > target){
                right = mid;
            } else{
                return true;
            }
        }
        // start means that the last element of this row is greater than target
        int start = max(0, left-1);
        // [start,stop)
        if(start > stop) return false;
        for(int i=start; i < stop; i++){
            vector<int>& curr = matrix[i];
            left = 0, right = n-1;
            if(right == 0 && curr[0] ==target) return true;
            while(left < right){
                mid = left+(right-left)/2;
                if(curr[mid] == target) return true;
                else if(curr[mid] > target){
                    right = mid;
                }
                else left = mid+1;
            }
            if(curr[left] == target || curr[right] == target) return true;
        }
        return false;
    }
};
// @lc code=end

