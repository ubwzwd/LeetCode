/*
 * @lc app=leetcode id=315 lang=java
 *
 * [315] Count of Smaller Numbers After Self
 */

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int len = nums.length;
        if (len == 0)
            return res;
        List<Integer> res = new ArrayList<Integer>(len);
        List<Integer> temp = new ArrayList<Integer>();
        temp.add(nums[len-1]);
        // begin from the last one
        for(int i = 0; i < len-2; i++)
        {
            int left = 0, right = temp.size();
            while(left < right)
            {
                int mid = left + (right - left)/2;
                if( temp.get(mid) >= nums[i])
                    right = mid;
                else left = mid + 1;

            }
            res.set(i,right);
        }
        return res;
    }
}

