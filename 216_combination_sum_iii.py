class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res = []

        def dfs(path, curr_num, total):
            if len(path)==k:
                if total == n:
                    res.append(list(path))
                return
            
            for i in range(curr_num, 10):
                path.append(i)
                dfs(path, i+1, total+i)
                path.pop()
            return
        dfs([], 1, 0)
        return res

if __name__ == "__main__":
    sol = Solution()
    print(sol.combinationSum3(3, 8))