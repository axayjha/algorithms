"""
https://leetcode.com/problems/diagonal-traverse/

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal 
order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

 

Note:

The total number of elements of the given matrix will not exceed 10,000.
"""


class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        from collections import defaultdict
        ans = []
        d = defaultdict(list)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                d[i+j].append((i, j, matrix[i][j]))

        flip = True
        for i in sorted(d.keys()):
            for j in sorted(d[i], reverse=flip):
                ans.append(j[2])
            flip = not flip
        return ans
