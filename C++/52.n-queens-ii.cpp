/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (53.83%)
 * Likes:    330
 * Dislikes: 128
 * Total Accepted:    109.9K
 * Total Submissions: 204K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        // a point at (row, col) is valide when col is valide
        vector<int> validate_col(n, true);
        // a point at (row, col) is valide when the row+col is valide in 45 degree, and the n-1 + row - col is valide in 135 degree
        vector<int> validate_45_degree(2*n-1, true);
        vector<int> validate_135_degree(2*n-1, true);
        int res = 0;
        // count is the number of queens that are already put on the chessboard
        int count = 0;
        totalNQueensRec(n, 0, res, validate_col, validate_45_degree, validate_135_degree);
        return res;
    }
private:
    void totalNQueensRec(int n, int count, int& res, vector<int>& validate_col, vector<int>& validate_45_degree, vector<int>& validate_135_degree){
        // if n queens have been put
        if(count == n){
            res++;
            return;
        }
        // if not, we can still put queens. Now it is the turn for the (count+1)-th. That means, now we are at count-th row
        for(int i = 0; i < n; i++){
            // check if the position is valide
            if(validate_col[i] && validate_45_degree[count+i] && validate_135_degree[n-1+count-i]){
                validate_col[i] = validate_45_degree[count+i] = validate_135_degree[n-1+count-i] = false;
                totalNQueensRec(n, count+1, res, validate_col, validate_45_degree, validate_135_degree);
                validate_col[i] = validate_45_degree[count+i] = validate_135_degree[n-1+count-i] = true;
            }
        }
    }
};
// @lc code=end

