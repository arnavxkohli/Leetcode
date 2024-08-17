from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        new_start, new_end = newInterval
        inserted = False
        for interval in intervals:
            cur_start, cur_end = interval
            if cur_end < new_start:
                res.append(interval)
            elif new_end < cur_start:
                if not inserted:
                    inserted = True
                    res.append([new_start, new_end])
                res.append(interval)
            if cur_start <= new_start <= cur_end:
                new_start = min(new_start, cur_start)
            if new_start <= cur_start <= new_end:
                new_end = max(new_end, cur_end)
        if not inserted:
            res.append([new_start, new_end])
        return res


solution = Solution()
print(solution.insert([[1,5]], [2,3]))