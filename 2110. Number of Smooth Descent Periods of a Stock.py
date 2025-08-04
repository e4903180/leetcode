class Solution(object):
    def getDescentPeriods(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if n==0:
            return 0
        count = 0
        total = 0
        for i in range(n):
            if i>0 and prices[i-1]-prices[i]==1:
                count+=1
            else: 
                count=1
            total+=count
        return total


if __name__ == "__main__":
    sol = Solution()
    prices = [3,2,1,4]
    print(sol.getDescentPeriods(prices))

    