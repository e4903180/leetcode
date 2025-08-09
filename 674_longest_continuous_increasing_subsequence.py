class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 1
        max_count = 0
        n = len(nums)
        if n <=1:
            return n
        for i in range(1, n):
            if nums[i]>nums[i-1]:
                count += 1
            else:
                count = 1
            max_count = max(max_count, count)
        return max_count



if __name__ == "__main__":
    sol = Solution()
    nums = [1,3,5,4,7]
    print(sol.findLengthOfLCIS(nums))