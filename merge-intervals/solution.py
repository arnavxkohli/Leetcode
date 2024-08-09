from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        res = []

        for interval in intervals:
            if len(res) == 0:
                res.append(interval)
            start, end = interval
            if start <= res[-1][1]:
                res[-1][1] = max(res[-1][1], end)
            else:
                res.append(interval)

        return res