/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (37.00%)
 * Likes:    848
 * Dislikes: 85
 * Total Accepted:    55K
 * Total Submissions: 148.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[0,0,0]]
 * 
 * Output:
 * [[0,0,0],
 * [0,1,0],
 * [0,0,0]]
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,1,1]]
 * 
 * Output:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,2,1]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return vector<vector<int>>{};
        int row = matrix.size(), col = matrix[0].size();
        int maximum = row+col;
        queue<pair<int,int>> Q;
        // put all the 0s into queue
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0) Q.push(make_pair(i,j));
                else matrix[i][j] = maximum;
            }
        }
        while(!Q.empty()){
            pair<int,int> index = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++){
                int nx = index.first+dx[i], ny = index.second+dy[i];
                // if (nx,ny) is out of range, or (nx,ny) has already been updated
                if(nx>=row || ny>=col || nx<0 || ny<0 || (matrix[nx][ny]<=matrix[index.first][index.second]+1)) continue;
                // if not, update
                matrix[nx][ny] = matrix[index.first][index.second]+1;
                // then push this point to the queue
                Q.push(make_pair(nx,ny));
            }
        }
        return matrix;
    }
};
// @lc code=end

