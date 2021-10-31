"""
https://leetcode.com/problems/longest-palindromic-subsequence/

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some 
or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.

"""
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        
        @lru_cache(None)
        def rec(i, j):
            
            if i == j:
                return 1
            elif i > j:
                return 0
            if s[i] == s[j]:
                return 2 + rec(i+1, j-1)
            else:
                return max(rec(i+1, j), rec(i, j-1))
            
        return rec(0, len(s)-1)
            
        
"""        
#WRONG SOLUTIONS 

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        def isPalin(s):
            return s==s[::-1]
        @lru_cache
        def rec(i):
            if i >= len(s):
                return ""
            else:
                taken = s[i] + rec(i+1)
                not_taken = rec(i+1)
                if isPalin(taken) and isPalin(not_taken):
                    return taken if len(taken) > len(not_taken) else not_taken
                elif isPalin(taken):
                    return taken
                elif isPalin(not_taken):
                    return not_taken
                else:
                    return s[i]
        return rec(0)              
            
        

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        def isPalin(s):
            return s==s[::-1]
        ans = 0
        self.maxlen = 0
        @lru_cache(None)
        def rec(i, temp):
            if isPalin(temp) and len(temp) > self.maxlen:
                # print(temp)
                self.maxlen = len(temp)
            if i >= len(s):
                return
            
            else:
                for j in range(i, len(s)):
                    temp += s[j]
                    # print(temp)
                    rec(j+1, temp)
                    temp = temp[:-1]
            
        rec(0, "")              
        return self.maxlen
            
        
        """
