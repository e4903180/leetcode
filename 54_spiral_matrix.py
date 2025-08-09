class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        n = len(matrix)
        m = len(matrix[0])
        count = 0
        start_x, end_x = 0, m
        start_y, end_y = 0, n
        res = []
        x, y = 0, 0
        while count<(m*n):
            for i in range(start_x, end_x):
                x = i
                res.append(matrix[y][x])
                count+=1
                print(matrix[y][x])
            start_y+=1
            if count == m*n:
                break
            for j in range(start_y, end_y):
                y = j
                res.append(matrix[y][x])
                count+=1
                print(matrix[y][x])
            if count == m*n:
                break
            end_x-=1
            for rev_i in range(end_x-1, start_x-1, -1):
                x = rev_i
                res.append(matrix[y][x])
                count+=1
                print(matrix[y][x])
            if count == m*n:
                break
            end_y-=1
            for rev_j in range(end_y-1, start_y-1, -1):
                y = rev_j
                res.append(matrix[y][x])
                count+=1
                print(matrix[y][x])
            if count == m*n:
                break
            start_x+=1
        return res
    
if __name__ == "__main__":
    sol = Solution()
    matrix = [[1,2,3],[4,5,6],[7,8,9]]
    res = sol.spiralOrder(matrix)
    print(res)

