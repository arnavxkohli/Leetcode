from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        res, last = 0, 0
        points.sort()
        for interval in points:
            if res == 0:
                res, last = 1, interval[1]
            if interval[0] <= last:
                last = min(last, interval[1])
            else:
                res, last = res+1, interval[1]
        return res
