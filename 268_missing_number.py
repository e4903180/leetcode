# ADD
# class Solution(object):
#     def missingNumber(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         total = sum(nums)
#         max_num = len(nums)
#         max_total = sum(range(0, max_num+1))
#         return max_total - total

# XOR
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        XOR_nums = 0
        for n in nums:
            XOR_nums ^= n
        max_num = len(nums)
        XOR_n_nature = 0
        for n in range(0, max_num+1):
            XOR_n_nature ^= n
        return XOR_nums^XOR_n_nature

    
if __name__ == "__main__":
    sol = Solution()
    nums = [0, 3, 1]
    print(sol.missingNumber(nums))