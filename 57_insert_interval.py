class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        n = len(intervals)
        ans = []
        i = 0
        while i<n and intervals[i][1]<newInterval[0]:
            ans.append(intervals[i])
            i+=1
        while i<n and intervals[i][1]>=newInterval[0] and intervals[i][0]<=newInterval[1]:
            newInterval[0] = min(intervals[i][0], newInterval[0])
            newInterval[1] = max(intervals[i][1], newInterval[1])
            i+=1
        ans.append(newInterval)
        while i<n and intervals[i][0]>newInterval[1]:
            ans.append(intervals[i])
            i+=1
        return ans
        

if __name__ == "__main__":
    sol = Solution()
    intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
    newInterval = [4,8]
    ans = sol.insert(intervals, newInterval)
    print(ans)