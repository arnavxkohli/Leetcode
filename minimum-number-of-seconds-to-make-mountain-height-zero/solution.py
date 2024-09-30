from typing import List
import heapq


class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        min_heap = []
        for w in workerTimes:
            heapq.heappush(min_heap, (w, w))
        used = []
        for _ in range(mountainHeight):
            t, w = heapq.heappop(min_heap)
            used.append((t, w))
            heapq.heappush(min_heap, (t+w, w))
        print(used)
        return 0