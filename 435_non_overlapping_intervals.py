# 按照結束時間排序
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        if len(intervals) == 0:
            return 0
        intervals.sort(key = lambda x:x[1]) # 按照先結束排序
        count = 1
        end = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] >= end: # 沒有重疊，計入count，更新end時間
                count+=1
                end = intervals[i][1]
        return len(intervals) - count
# Time: O(nlogn) + O(n), Space: O(1)


# 按照先開始排序
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        if len(intervals) == 0:
            return 0
        intervals.sort() # 按照先開始排序
        count = 0
        prev_end = intervals[0][1]

        for i in range(1, len(intervals)):
            if intervals[i][0] < prev_end:
                count+=1
                prev_end = min(prev_end, intervals[i][1])
            else:
                prev_end = intervals[i][1]
        return count
# Time: O(nlogn) + O(n), Space: O(1)


if __name__ == "__main__":
    sol = Solution()
    intervals = [[1,2],[2,3],[3,4],[1,3]]
    print(sol.eraseOverlapIntervals(intervals))