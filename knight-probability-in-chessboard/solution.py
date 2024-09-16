class Solution:

    def __init__(self):
        self.moves = [(2, 1), (1, 2), (2, -1), (1, -2), (-2, 1), (-1, 2), (-1, -2), (-2, -1)]
        self.n = None
        self.cache = {}

    def dp(self, k, row, column):
        if row < 0 or row >= self.n or column < 0 or column >= self.n:
            return 0
        if k == 0:
            return 1
        if (row, column, k) in self.cache:
            return self.cache[(row, column, k)]
        result = 0
        for dr, dc in self.moves:
            result += (self.dp(k-1, row+dr, column+dc))/8
        self.cache[(row, column, k)] = result
        return result

    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        self.n = n
        return self.dp(k, row, column)
