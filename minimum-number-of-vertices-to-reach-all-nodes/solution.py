from typing import List


class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        incoming = set([i for i in range(n)])
        for _, end in edges:
            if end in incoming: incoming.remove(end)
        return list(incoming)