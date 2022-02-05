/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (48.20%)
 * Likes:    1248
 * Dislikes: 227
 * Total Accepted:    142.2K
 * Total Submissions: 287.5K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 * 
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 * 
 * 
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 * 
 * 
 * Write a function to compute the next state (after one update) of the board
 * given its current state. The next state is created by applying the above
 * rules simultaneously to every cell in the current state, where births and
 * deaths occur simultaneously.
 * 
 * Example:
 * 
 * 
 * Input: 
 * [
 * [0,1,0],
 * [0,0,1],
 * [1,1,1],
 * [0,0,0]
 * ]
 * Output: 
 * [
 * [0,0,0],
 * [1,0,1],
 * [0,1,1],
 * [0,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
    int dx[8] = {1,1,0,-1,-1,-1,0,1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
public:

    // // time complexity: O(mn), space complexity: O(mn)
    // void gameOfLife(vector<vector<int>>& board) {
    //     int row = board.size();
    //     if(row == 0) return;
    //     int col = board[0].size();
    //     if(col == 0) return;
    //     int count = 0, nx = 0, ny = 0;
    //     vector<vector<int>> temp = board;
    //     for(int i = 0; i < row; i++){
    //         for(int j = 0; j < col; j++){
    //             count = 0;
    //             for(int k = 0; k < 8; k++){
    //                 nx = i+dx[k];
    //                 ny = j+dy[k];
    //                 if(nx >= 0 && nx < row && ny >= 0 && ny < col){
    //                     if(temp[nx][ny] == 1) count++;
    //                 }
    //             }
    //             if(count == 3) board[i][j] = 1;
    //             else if(count != 2) board[i][j] = 0;
    //         }
    //     }
    // }

    // time complexity: O(mn), space complexity: O(1)
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        if(row == 0) return;
        int col = board[0].size();
        if(col == 0) return;
        // now there are 2 status: b'01 and b'00
        // if the pixel is already judged, there where be 4 status. b'xx, the first will be the new status
        // and the second can be the previous status.
        // so if the number is odd, the previous status is 1, if is even, the previous status is 0
        int count = 0, nx = 0, ny = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                count = 0;
                for(int k = 0; k < 8; k++){
                    nx = i+dx[k];
                    ny = j+dy[k];
                    if(nx >= 0 && nx < row && ny >= 0 && ny < col && board[nx][ny]%2){
                        count++;
                    }
                }
                if(count == 3) board[i][j] += 2;
                else if (count == 2) board[i][j] += board[i][j]*2;
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                board[i][j] = (board[i][j] > 1);
            }
        }
    }
};
// @lc code=end

