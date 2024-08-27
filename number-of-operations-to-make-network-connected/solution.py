from typing import List
from collections import deque


class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n-1: return -1
        adj = [[] for _ in range(n)]
        for u, v in connections:
            adj[u].append(v)
            adj[v].append(u)
        visited = set()
        extras = 0
        for i in range(n):
            if i not in visited:
                extras += 1
                visited.add(i)
                bfs = deque([i])
                while bfs:
                    curr = bfs.popleft()
                    for child in adj[curr]:
                        if child not in visited:
                            visited.add(child)
                            bfs.append(child)
        return extras - 1
