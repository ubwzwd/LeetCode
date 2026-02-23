/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  vector<unordered_set<char>> row_set, col_set, small_set;
  vector<vector<char>> temp;
  bool solved;

  int findSmallBlock(int x, int y) { return (x / 3) * 3 + y / 3; }

  bool isValidOption(int x, int y, char c) {
    if (x < 0 || x >= 9 || y < 0 || y >= 9)
      return false;
    if (temp[x][y] != '.')
      return false;
    return !row_set[x].count(c) && !col_set[y].count(c) &&
           !small_set[findSmallBlock(x, y)].count(c);
  }

  void placeNum(int x, int y, char c) {
    temp[x][y] = c;
    row_set[x].insert(c);
    col_set[y].insert(c);
    small_set[findSmallBlock(x, y)].insert(c);
  }

  void removeNum(int x, int y, char c) {
    temp[x][y] = '.';
    row_set[x].erase(c);
    col_set[y].erase(c);
    small_set[findSmallBlock(x, y)].erase(c);
  }

  void proceedNext(int x, int y) {
    if (solved || x == 8 && y == 8) {
      solved = true;
      return;
    }
    if (y == 8)
      recursion(x + 1, 0);
    else
      recursion(x, y + 1);
    return;
  }

  void recursion(int x, int y) {
    // if we can put some new number here
    if (temp[x][y] == '.') {
      for (int i = 0; i < 9; i++) {
        char c = i + '1';
        if (isValidOption(x, y, c)) {
          placeNum(x, y, c);
          proceedNext(x, y);
          if (!solved)
            removeNum(x, y, c);
        }
      }
    } else {
      proceedNext(x, y);
    }
  }

public:
  Solution()
      : row_set(9, unordered_set<char>()), col_set(9, unordered_set<char>()),
        small_set(9, unordered_set<char>()), temp(9, vector<char>(9, '.')), solved(false) {}

  void solveSudoku(vector<vector<char>> &board) {
    // init temp
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.')
          placeNum(i, j, board[i][j]);
      }
    }

    // recursion
    recursion(0, 0);
    board = temp;
    return;
  }
};

// @lc code=end
