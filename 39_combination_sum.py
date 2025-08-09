class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        def dfs(i, path, total):
            print(path, total)
            if i>=len(candidates) or total > target:
                return
            if total == target:
                res.append(path.copy())
                return
            path.append(candidates[i])
            dfs(i, path, total+candidates[i])
            path.pop()
            dfs(i+1, path, total)
        
        dfs(0, [], 0)
        return res

if __name__ == "__main__":
    sol = Solution()
    candidates = [2,3,6,7]
    target = 7
    print(sol.combinationSum(candidates, target))