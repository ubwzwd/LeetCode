/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> mock_stack;
        string res = "";
        for (int i = 0; i < num.length(); i++)
        {
            int number = num[i] - '0';
            // if the current element < the last one
            while(mock_stack.size()!=0 && mock_stack[mock_stack.size()-1] > number && k>0)
            {
                mock_stack.pop_back();
                k--;
            }
            if (!(number==0 && mock_stack.size()==0))
            {
                mock_stack.push_back(number);
            }
        }
        while(mock_stack.size()>0 && k>0)
        {
            mock_stack.pop_back();
            k--;
        }
        for(int i = 0; i < mock_stack.size(); i++)
        {
            res.append(to_string(mock_stack[i]));
        }
        if (res == "")
            return "0";
        else
            return res;
    }
};

// int main()
// {
//     string s = "1432219";
//     Solution so;
//     string s2 = so.removeKdigits(s, 3);
//     return 0;
// }

