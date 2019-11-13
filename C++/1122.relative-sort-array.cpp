/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 *
 * https://leetcode.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (66.23%)
 * Likes:    283
 * Dislikes: 20
 * Total Accepted:    28.6K
 * Total Submissions: 43K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all
 * elements in arr2 are also in arr1.
 * 
 * Sort the elements of arr1 such that the relative ordering of items in arr1
 * are the same as in arr2.  Elements that don't appear in arr2 should be
 * placed at the end of arr1 in ascending order.
 * 
 * 
 * Example 1:
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 * 
 * 
 * Constraints:
 * 
 * 
 * arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * Each arr2[i] is distinct.
 * Each arr2[i] is in arr1.
 * 
 * 
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
    void swap(int& a, int& b){
        int c = a;
        a = b;
        b = c;
    }

    void quickSort(vector<int>& nums, int first, int last){
        if(first >= last) return;
        int p = first;
        int pivot = nums[last];
        for(int i = first; i < last; i++){
            if(nums[i] < pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[last]);
        quickSort(nums, first, p-1);
        quickSort(nums,p+1, last);
    }
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.empty()) return arr1;
        if(arr2.empty()){
            quickSort(arr1, 0, arr1.size()-1);
            return arr1;
        }
        unordered_map<int, int> map;
        vector<int> residual;
        // build a hash table
        for(int i = 0; i < arr2.size(); i++){
            map.insert(make_pair(arr2[i], 0));
        }
        for(int i = 0; i < arr1.size(); i++){
            if(map.find(arr1[i]) == map.end()){
                residual.push_back(arr1[i]);
            }
            else{
                map[arr1[i]]++;
                
            }
        }
        vector<int> res;
        res.reserve(arr1.size()+1);
        for(int i = 0; i < arr2.size(); i++){
            res.insert(res.end(), map[arr2[i]], arr2[i]);
        }
        quickSort(residual, 0, residual.size()-1);
        res.insert(res.end(), residual.begin(), residual.end());
        return res;
    }
};
// @lc code=end

