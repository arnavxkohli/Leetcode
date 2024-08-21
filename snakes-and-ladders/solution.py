from typing import List
from collections import deque


class Solution:
    def __init__(self):
        self.n = 0

    def get_index(self, row, col):
        index = (self.n - row - 1) * self.n
        index += self.n - col if (self.n - row - 1) % 2 else col + 1
        return index

    def snakesAndLadders(self, board: List[List[int]]) -> int:
        self.n = len(board)
        shortcut = {}
        for r in range(self.n):
            for c in range(self.n):
                if board[r][c] > -1:
                    shortcut[self.get_index(r, c)] = board[r][c]
        bfs = deque([(1, -1)])
        visited = set()
        while bfs:
            cur, moves = bfs.popleft()
            if cur == self.n ** 2: return moves+1
            for nex in range(cur+1, min(self.n ** 2 + 1, cur+7)):
                if nex not in visited:
                    visited.add(nex)
                    bfs.append((shortcut.get(nex, nex), moves+1))
        return -1
