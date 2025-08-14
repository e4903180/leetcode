class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0
        for i in range(32):
            result <<= 1
            result |= n & 1
            n >>= 1
        return result

n = 43261596
solution = Solution()
print(solution.reverseBits(n))  # Output: 964176192