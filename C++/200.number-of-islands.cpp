/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.05%)
 * Likes:    3236
 * Dislikes: 116
 * Total Accepted:    435.9K
 * Total Submissions: 1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    int dx[4] {1,0,-1,0};
    int dy[4] {0,1,0,-1};
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int col = grid.size();
        int row = grid[0].size();
        int total = row*col;
        int res = 0;
        for(int x = 0; x < col; x++){
            for(int y = 0; y < row; y++){
                if(grid[x][y] == '1'){
                    res++;
                    grid[x][y] = '0';
                    queue<pair<int, int>> Q;
                    Q.push(make_pair(x,y));
                    while(!Q.empty()){
                        int new_x = Q.front().first, new_y = Q.front().second;
                        Q.pop();
                        for(int i = 0; i < 4; i++){
                            int nx = new_x+dx[i], ny = new_y+dy[i];
                            if(nx >= 0 && ny >= 0 && nx < col && ny < row && grid[nx][ny] == '1'){
                                grid[nx][ny] = '0';
                                Q.push(make_pair(nx,ny));
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

