# class Solution(object):
#     def findMin(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         if len(nums) == 1: return nums[0]
#         if len(nums) == 2: return min(nums[0], nums[1])

#         left = 0
#         right = len(nums)-1
#         mid = int(left + (right-left)/2)
#         print(nums, left, mid, right)
#         if nums[left] < nums[mid] and nums[mid] < nums[right]:
#             return nums[left]
#         elif nums[left] > nums[mid] and nums[mid] < nums[right]:
#             return self.findMin(nums[left:mid+1])
#         elif nums[left] < nums[mid] and nums[mid] > nums[right]:
#             return self.findMin(nums[mid:right+1])

class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = len(nums)-1

        while left<right:
            mid = left + (right-left)//2
            if nums[mid] > nums[right]:
                left = mid+1
            else:
                right = mid
        return nums[left]


if __name__ == "__main__":
    sol = Solution()
    nums = [3,4,5,1,2]
    print(sol.findMin(nums))