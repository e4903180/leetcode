class Solution(object):
    def wordBreak(self, s:str, wordDict:list[str]):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        word_set = set(wordDict)
        n = len(s)
        cache = [False]*(n+1)
        cache[0] = True
        for i in range(1, n+1):
            for j in range(i):
                if cache[j] and s[j:i] in word_set:
                    cache[i] = True
                    break
        return cache[n]


if __name__ == "__main__":
    sol = Solution()
    s = "applepenapple"
    wordDict = ["pen", "apple"]
    print(sol.wordBreak(s, wordDict))