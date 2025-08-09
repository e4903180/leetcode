class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        min_prices = prices[0] # 紀錄最低進場價
        profit = 0
        max_profit = 0
        for price in prices:
            if price<min_prices:
                min_prices = price # 更新最低價
            else:
                profit = price - min_prices # 非最低價，賣出記錄獲利
            max_profit = max(max_profit, profit) # 更新最高獲利
        return max_profit
        

        
if __name__ == "__main__":
    sol = Solution()
    prices = [7,1,5,3,6,4]
    print(sol.maxProfit(prices))