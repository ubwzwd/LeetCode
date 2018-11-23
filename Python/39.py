'''
Combinational Sum

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
'''


class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        candidates.sort()
        self.dfs(candidates, target, res, [])
        return res
    
    def dfs(self, candidate, target, res, temp):
        if target < 0:
            return
        elif target == 0:
            res.append(temp)
            return
        else:
            for cand in candidate:
                if cand > target:
                    return
                if not temp or cand >= temp[-1]:
                    self.dfs(candidate, target - cand, res, temp+[cand])
        return

candidate = [2,3]
a = Solution()
s = a.combinationSum(candidate, 8)
print(s)

'''
result runtime: 76ms
'''