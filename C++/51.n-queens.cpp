/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// each queen would occupy the 8 directions from it
// so if we want to put n queens on a n-by-n chessboard, we should let every row and colum has a queen, and only one queen on each
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        // set a vector to store the location of each queen
        vector<string> queen_pos;
        string temp;
        for (int i = 0; i < n; i++)
        {
            temp.append(".");
        }
        for (int i = 0; i < n; i++)
        {
            queen_pos.push_back(temp);
        }
        vector<vector<string>> res;
        // initialize the chessboard, 0 means unoccupied, 1 means occupied
        vector<int> chessboard_row(n, 0);
        vector<vector<int>> chessboard(n, chessboard_row);

        solveNQueensRec(0, n, chessboard, queen_pos, res);

        return res;
    }

private:
    const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    void putAQueen(int x, int y, vector<vector<int>> &chessboard)
    {
        chessboard[x][y] = 1;
        for (int i = 0; i < chessboard.size(); i++)
        {
            for (int j = 0; j < 8; j++)
            {
                int new_x = x + i * this->dx[j];
                int new_y = y + i * this->dy[j];
                if (new_x >= 0 && new_x < chessboard.size() && new_y >= 0 && new_y < chessboard.size())
                    chessboard[new_x][new_y] = 1;
            }
        }
    }

    void solveNQueensRec(int k, int n, vector<vector<int>> &chessboard, vector<string> &temp, vector<vector<string>> &res)
    {
        // k is the number of queens already put
        if (k == n)
        {
            res.push_back(temp);
            return;
        }
        // try every colum
        for (int i = 0; i < n; i++)
        {
            if (chessboard[k][i] == 0)
            {
                vector<vector<int>> chessboard_temp = chessboard;
                temp[k][i] = 'Q';
                putAQueen(k, i, chessboard);
                solveNQueensRec(k + 1, n, chessboard, temp, res);
                chessboard = chessboard_temp;
                temp[k][i] = '.';
            }
        }
    }
};

// int main()
// {
//     Solution s;
//     vector<int> chessboard_row(4, 0);
//     vector<vector<int>> chessboard(4, chessboard_row);

//     for(int i = 0; i < 4; i++)
//     {
//         for(int j = 0; j < 4;j++)
//             cout<<chessboard[i][j]<<" ";
//         cout <<endl;
//     }

//     s.putAQueen(2,2,chessboard);

//     for(int i = 0; i < 4; i++)
//     {
//         for(int j = 0; j < 4;j++)
//             cout<<chessboard[i][j]<<" ";
//         cout <<endl;
//     }

//     return 0;
// }
