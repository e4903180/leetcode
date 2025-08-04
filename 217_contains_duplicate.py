class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        seen = set(nums)
        if len(seen) == len(nums):
            return False
        else :
            return True

if __name__ == "__main__":
    sol = Solution()
    nums = [0, 1, 1, 2, 3]
    print(sol.containsDuplicate(nums))