from collections import Counter
import heapq

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freqs = Counter(nums)
        min_heap = []
        for num, count in freqs.items():
            heapq.heappush(min_heap, (count, num))
            if len(min_heap)>k:
                heapq.heappop(min_heap)
        return [num for count, num in min_heap]
# Time: O(nlogk), Space:O(k)
# heap push, pop是logk，做n次
# 一般排序要nlogn，當n>>k時不優

if __name__ == "__main__":
    solution = Solution()
    nums = [1, 1, 1, 2, 2, 3]
    k = 2
    result = solution.topKFrequent(nums, k)
    print("Top", k, "Frequent Elements:", result)