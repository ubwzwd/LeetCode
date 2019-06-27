/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        generateParenthesisRec(n, n, res, temp);
    }
private:
    void generateParenthesisRec(int n, int diff, vector<string>& res, string& temp)
    {
        if(n <= 0)
            return;
    }
};

