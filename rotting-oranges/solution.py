from typing import List
from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    grid[r][c] = (2, 0)
                elif grid[r][c] == 1:
                    grid[r][c] = (1, 1000)
                else:
                    grid[r][c] = (0, 0)
        nbr = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == (2, 0):
                    bfs = deque([(r, c, 0)])
                    while bfs:
                        row, col, time = bfs.popleft()
                        for nr, nc in nbr:
                            nr, nc = row + nr, col + nc
                            if 0 <= nr < rows and 0 <= nc < cols:
                                orange, minutes = grid[nr][nc]
                                if orange == 1 and time + 1 < minutes:
                                    grid[nr][nc] = (1, time + 1)
                                    bfs.append((nr, nc, time + 1))
        max_time = 0
        for row in grid:
            for _, time in row:
                max_time = max(max_time, time)
        return max_time if max_time < 1000 else -1