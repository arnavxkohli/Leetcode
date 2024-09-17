class Solution:

    def __init__(self):
        self.m = 0
        self.n = 0
        self.directions = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        self.mod = 10 ** 9 + 7
        self.cache = {}

    def dp(self, moves, row, col):
        if row < 0 or row >= self.m or col < 0 or col >= self.n:
            return 1
        if moves == 0:
            return 0
        if (moves, row, col) in self.cache:
            return self.cache[(moves, row, col)]
        result = 0
        for dr, dc in self.directions:
            result += self.dp(moves-1, row+dr, col+dc) % self.mod
        self.cache[(moves, row, col)] = (result) % self.mod
        return self.cache[(moves, row, col)]

    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        self.m = m
        self.n = n
        return self.dp(maxMove, startRow, startColumn)
