from typing import List
import heapq


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = [[] for _ in range(n)]
        for start, end, weight in times:
            graph[start-1].append((end-1, weight))
        distances = [10**8] * n
        min_heap, distances[k-1] = [], 0
        heapq.heappush(min_heap, (0, k-1))
        while min_heap:
            dist, cur = heapq.heappop(min_heap)
            for nex, weight in graph[cur]:
                if dist + weight < distances[nex]:
                    distances[nex] = dist + weight
                    heapq.heappush(min_heap, (distances[nex], nex))
        res = -1
        for distance in distances:
            if distance == 10**8: return -1
            res = max(res, distance)
        return res