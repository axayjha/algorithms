"""


https://leetcode.com/problems/01-matrix/submissions/


Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]


 
"""
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        import sys
        res = [[sys.maxsize]*len(matrix[0]) for i in range(len(matrix))]
        q = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    res[i][j] = 0
                    q.append((i, j))
        offset = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while q:
            n = q.pop(0)
            for k in offset:
                x = n[0] + k[0]
                y = n[1] + k[1]
                if (x >= 0 and x < len(matrix) and y >= 0 and y < len(matrix[0]) and res[n[0]][n[1]] + 1 < res[x][y]):
                    res[x][y] = res[n[0]][n[1]] + 1
                    q.append((x, y))
        return res                    
            
                        
