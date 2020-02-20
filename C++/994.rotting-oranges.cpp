/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Easy (46.59%)
 * Likes:    786
 * Dislikes: 99
 * Total Accepted:    44.1K
 * Total Submissions: 93.7K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * In a given grid, each cell can have one of three values:
 * 
 * 
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is adjacent (4-directionally) to a
 * rotten orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange.  If this is impossible, return -1 instead.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation:  The orange in the bottom left corner (row 2, column 0) is
 * never rotten, because rotting only happens 4-directionally.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[0,2]]
 * Output: 0
 * Explanation:  Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] is only 0, 1, or 2.
 * 
 * 
 * 
 * 
 */
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
    int dx[4]{-1,1,0,0};
    int dy[4]{0,0,-1,1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return -1;
        int col = grid[0].size();
        if(col == 0) return 0;
        // 0 means not visited
        vector<vector<int>> time(row, vector<int>(col, -1));
        queue<pair<int,int>> q;
        // put all the rotted ones into queue
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    time[i][j] = 0;
                }
            }
        }
        int res = 0;
        // bfs
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    time[nx][ny] = time[x][y]+1;
                    q.push({nx,ny});
                    res = time[nx][ny];
                }
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
};
// @lc code=end

