"""
    https://leetcode.com/problems/target-sum/
"""
import sys 
# brute force
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        def recur(index, summ):
            if index == len(nums):
                if summ == 0:
                    recur.count+=1
                return    
            else:
                recur(index+1, summ-nums[index])
                recur(index+1, summ+nums[index])
        recur.count = 0
        recur(0, S)
        return recur.count
                
# DP
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        memo = [[sys.maxsize]*2001 for i in range(len(nums))] 
        
        def calculate(i, summ, memo):
            if i == len(nums):
                if summ == S:
                    return 1
                else: return 0
            else:
                if memo[i][summ + 1000] != sys.maxsize :
                    return memo[i][summ+1000]
                add = calculate(i+1, summ + nums[i], memo)
                subtract = calculate(i+1, summ - nums[i], memo)
                memo[i][summ+1000] = add + subtract
                return memo[i][summ + 1000]
        return calculate(0, 0, memo)         
