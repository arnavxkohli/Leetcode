from typing import List
import heapq


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        pq = []
        for x, y in points:
            if len(pq) < k:
                heapq.heappush(pq, [-(x**2 + y**2), x, y]) # max heap
            else:
                heapq.heappushpop(pq, [-(x**2 + y**2), x, y]) # pop max element once heap reaches size k to maintain k smallest
        return [element[1:] for element in pq]