from collections import deque
from typing import List


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows, cols = len(heights), len(heights[0])
        def bfs(row, col, ocean_set):
            bq = deque([(row, col)])
            while bq:
                row, col = bq.popleft()
                if (row, col) in ocean_set: continue
                ocean_set.add((row, col))
                for nr, nc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                    nr, nc = row + nr, col + nc
                    if (0 <= nr < rows) and (0 <= nc < cols) and heights[nr][nc] >= heights[row][col]:
                        bq.append((nr, nc))
        pacific_set, atlantic_set = set(), set()
        for r in range(rows):
            bfs(r, 0, pacific_set)
            bfs(r, cols-1, atlantic_set)
        for c in range(cols):
            bfs(0, c, pacific_set)
            bfs(rows-1, c, atlantic_set)
        return [list(coords) for coords in pacific_set & atlantic_set]