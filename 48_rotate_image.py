# class Solution(object):
#     def rotate(self, matrix):
#         """
#         :type matrix: List[List[int]]
#         :rtype: None Do not return anything, modify matrix in-place instead.
#         """
#         stack = []
#         len_x = len(matrix)
#         len_y = len(matrix[0])
#         for x in range(len_x):
#             for y in range(len_y):
#                 stack.append(matrix[y][x])
#         for rev_y in range(len_y-1, -1, -1):
#             for x in range(len_x):
#                 matrix[rev_y][x] = stack.pop()
#         return

class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for row in matrix:
            row.reverse()
        return

if __name__ == "__main__":
    sol = Solution()
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    sol.rotate(matrix)
    print(matrix)