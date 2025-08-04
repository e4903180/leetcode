class Solution(object):
    def threeSum(self, nums: list[int]) ->list[list[int]]:
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        n = len(nums)
        res = []
        for i in range(n):
            if i>0 and nums[i]==nums[i-1]:
                continue
            left = i+1
            right = n-1
            while left<right:
                total = nums[i] + nums[left] + nums[right]
                if total==0:
                    res.append([nums[i], nums[left], nums[right]])
                    right-=1
                    left+=1
                    while left<right and nums[left] == nums[left-1]:
                        left+=1
                    while left<right and nums[right] == nums[right+1]:
                        right-=1
                elif total<0:
                    left+=1
                elif total>0:
                    right-=1
        return res


if __name__ == "__main__":
    sol = Solution()
    nums = [-2,0,1,1,2]
    ans = sol.threeSum(nums)
    print(ans)