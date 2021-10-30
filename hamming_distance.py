"""
    https://leetcode.com/problems/hamming-distance/
"""    


class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        cnt = 0
        for i in range(32):
            cnt += (x&1) ^ (y&1)
            x = x>>1
            y = y>>1
        return cnt            
            
                
        
