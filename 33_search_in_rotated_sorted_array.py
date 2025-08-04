class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] >= nums[right]: #left sorted
                if nums[left] <= target and target < nums[mid]:
                    right = mid-1
                else:
                    left = mid+1
            else: # right sorted
                if nums[mid] < target and target <= nums[right]:
                    left = mid+1
                else:
                    right = mid-1

        return -1

if __name__ == "__main__":
    sol = Solution()
    nums = [1, 3]
    target = 3
    print(sol.search(nums, target))