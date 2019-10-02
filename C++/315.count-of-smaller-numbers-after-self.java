import java.util.Arrays;

/*
 * @lc app=leetcode id=315 lang=java
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (38.86%)
 * Likes:    1276
 * Dislikes: 59
 * Total Accepted:    83.8K
 * Total Submissions: 215.6K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 * 
 * Example:
 * 
 * 
 * Input: [5,2,6,1]
 * Output: [2,1,1,0] 
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 */

// import java.util.List;
// import java.util.ArrayList;W

class Solution {
    public List<Integer> countSmaller(int[] nums) {
        // insert sorting
        int len = nums.length;
        if(len == 0)
        {
            return new ArrayList<Integer>();
        }
        int[] temp_res = new int[len];
        List<Integer> temp = new ArrayList<Integer>();
        temp.add(nums[len-1]);

        // now to implement the insert sort
        // from the right to the left
        // the last element is already sorted
        for(int i = len-2; i >=0; i--)
        {
            int left = 0, right = temp.size();
            // f
            while(left < right)
            {
                int mid = left +(right-left)/2;
                if(temp.get(mid)>nums[i])
                    right = mid;
                else left = mid+1;
            }
            temp_res[i] = right;
            temp.add(right, nums[i]);
        }
        
        List<Integer> res = new ArrayList<Integer>(Arrays.asList(temp_res));
        return res;
    }
}

// vector<int> countSmaller(vector<int>& nums)
// {   
//     int len = nums.size();
//     if(len == 0)
//         return vector<int> {};
//     vector<int> res(len);
//     vector<int> temp{nums[len-1]};
//     // begin from the last line
//     for(int i = len-2; i>=0; i--)
//     {
//         int left = 0, right = temp.size();
//         while(left < right)
//         {
//             int mid = left + (right-left)/2;
//             if(temp[mid] >= nums[i])
//                 right = mid;
//             else left = mid+1;
//         }
//         res[i] = right;
//         temp.insert(temp.begin()+right, nums[i]);
//     }
//     return res;
// }
// };

