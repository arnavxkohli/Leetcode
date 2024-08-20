from typing import List
from collections import deque


class Solution:
    def __init__(self):
        self.bank = None
        self.genes = ('A', 'G', 'T', 'C')
        self.start = ''
        self.end = ''
        self.visited = {}

    def recursive(self, curr, depth):
        if len(self.visited) == 32: return
        for index in range(8):
            for char in self.genes:
                new_curr = curr[:index] + char + curr[index+1:]
                if new_curr == self.end:
                    self.visited[new_curr] = depth+1
                    return
                if new_curr not in self.visited:
                    self.visited[new_curr] = depth+1
                    if new_curr in self.bank:
                        self.recursion(new_curr, depth+1)

    def iterative(self, startGene, endGene, bank):
        if startGene == endGene: return 0
        if endGene not in bank: return -1
        bank = set(bank)
        genes = ('A', 'G', 'T', 'C')
        visited = set([startGene])
        bfs = deque([(startGene, 0)])
        while bfs:
            curr, depth = bfs.popleft()
            for index in range(8):
                for char in genes:
                    new_curr = curr[:index] + char + curr[index+1:]
                    if new_curr == endGene: return depth+1
                    if new_curr not in visited and new_curr in bank:
                        visited.add(new_curr)
                        bfs.append((new_curr, depth+1))
        return -1

    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        if startGene == endGene: return 0
        if endGene not in bank: return -1
        self.start, self.end = startGene, endGene
        self.bank = set(bank)
        self.visited[startGene] = 0
        self.recursive(startGene, 0)
        return self.visited.get(endGene, -1)
