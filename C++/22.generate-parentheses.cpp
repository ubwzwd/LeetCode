/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        generateParenthesisRec(n, n, res, temp);
        return res;
    }
private:
    // choose the right signal to loop
    void generateParenthesisRec(int left, int right, vector<string>& res, string& temp)
    {
        if(left < 0 || right < 0)
            return;
        // diff means the number of '(' minus the number of ')'
        if(left == 0 && right == 0)
        {
            res.push_back(temp);
            return;
        }
        if(left > 0)
        {
            temp.append("(");
            generateParenthesisRec(left - 1,right, res, temp);
            temp.pop_back();
        }
        if(right > 0 && right > left)
        {
            temp.append(")");
            generateParenthesisRec(left, right - 1, res, temp);
            temp.pop_back();
        }
        
    }
};

// int main()
// {
//     Solution s;
//     vector<string> res = s.generateParenthesis(3);
    
//     return 0;
// }

