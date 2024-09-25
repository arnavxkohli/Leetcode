from typing import List
from collections import deque


class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        graph = [[] for _ in range(n)]
        for i, m in enumerate(manager):
            if m >= 0: graph[m].append(i)
        bfs = deque([(headID, 0)])
        res = 0
        while bfs:
            curr, time = bfs.popleft()
            inform_time = informTime[curr]
            res = max(res, time)
            for child in graph[curr]:
                bfs.append((child, time + inform_time))
        return res