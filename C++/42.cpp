/*
https://leetcode.com/problems/trapping-rain-water/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        bool sign = false;
        int sum = 0;
        int temp1;
        vector<int> vectorB, vectorE;
        int _begin, _end;
        for (_begin = 0; begin < len; _begin++)
        {
            if (height[_begin] != 0)
                break;
        }
        for (_end = len - 2; _end >= 0; _end--)
        {
            if (height[_end - 1] < height[_end])
                break;
        }
    }
};