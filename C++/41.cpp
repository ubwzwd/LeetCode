/*
First Missing Positive

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

Note:
Your algorithm should run in O(n) time and uses constant extra space.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.size()==0) return 1;
        sort(nums.begin(), nums.end());
        int temp = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= 0)
                continue;
            else if(i>0 && nums[i]==nums[i-1]) continue;
            else
            {
                if (nums[i] != temp)
                    return temp;
            }
        }
        return nums[nums.size() - 1] + 1;
    }
};

int main()
{
    vector<int> nums{1,3,4};
    Solution s;
    int a = s.firstMissingPositive(nums);
    cout << a;
    return 0;
}