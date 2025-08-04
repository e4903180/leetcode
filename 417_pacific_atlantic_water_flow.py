class Solution(object):
    def pacificAtlantic(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: List[List[int]]
        """
        ROW = len(heights)
        COL = len(heights[0])
        def dfs(row, col, visit, prevHeight):
            if (row, col) in visit or row<0 or col<0 or row==ROW or col==COL or heights[row][col]<prevHeight:
                return
            visit.add((row, col))
            dfs(row+1, col, visit, heights[row][col])
            dfs(row-1, col, visit, heights[row][col])
            dfs(row, col+1, visit, heights[row][col])
            dfs(row, col-1, visit, heights[row][col])

        pac , atl = set(), set()

        for m in range(ROW):
            dfs(m, 0, pac, heights[m][0])
            dfs(m, COL-1, atl, heights[m][COL-1])
        for n in range(COL):
            dfs(0, n, pac, heights[0][n])
            dfs(ROW-1, n, atl, heights[ROW-1][n])

        res = []
        for m in range(ROW):
            for n in range(COL):
                if (m, n) in pac and (m, n) in atl:
                    res.append([m, n])
        return res
    
if __name__ == "__main__":
    sol = Solution()
    heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    print(sol.pacificAtlantic(heights))

    