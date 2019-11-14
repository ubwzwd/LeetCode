/*
找到N以内所有的质数

[2, sqrt(n)]
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int removeElement(vector<int>&nums, int val){
    if(nums.empty()) return 0;
    int curr = 0, prev = 0;
    while(curr < nums.size()){
        if(nums[curr] != val){
            if(curr != prev){
                nums[prev+1] = nums[curr];
            }
            curr++;
            prev++;
        }
        else{
            curr++;
        }
    }
    return prev+1;
}