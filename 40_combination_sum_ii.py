class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        candidates.sort()
        
        def dfs(i, path, total):
            print(path)
            if total == target: # 找到答案
                res.append(list(path))
                return
            if total>target or i==len(candidates): # 失敗返回
                return


            # 從當前的數字加
            path.append(candidates[i])
            dfs(i+1, path, total+candidates[i])
            # 用下一個數字開始加
            path.pop()
            while i<len(candidates)-1 and candidates[i] == candidates[i+1]:
                i+=1
            dfs(i+1, path, total)
            return
        dfs(0, [], 0)
        return res
    
if __name__ == "__main__":
    sol = Solution()
    candidates = [2,5,2,1,2]
    target = 5
    print(sol.combinationSum2(candidates, target))