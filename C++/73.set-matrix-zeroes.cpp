/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (40.97%)
 * Likes:    1412
 * Dislikes: 242
 * Total Accepted:    254.2K
 * Total Submissions: 613.7K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // space: O(m+n)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        if(n == 0) return;
        vector<int> xs(m,0);
        vector<int> ys(n,0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0) {
                    xs[i]++;
                    ys[j]++;
                }
            }
        }
        for(int i = 0; i < m; i++){
            if(xs[i] > 0){
                for(int k = 0; k < n; k++){
                    matrix[i][k] = 0;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(ys[i] > 0){
                for(int k = 0; k < m; k++){
                    matrix[k][i] = 0;
                }
            }
        }
    }
};
// @lc code=end

