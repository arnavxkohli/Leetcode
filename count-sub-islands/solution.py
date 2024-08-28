from typing import List
from collections import deque


class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        res = 0
        rows, cols = len(grid1), len(grid1[0])
        visited = set()
        nbr = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        for r in range(rows):
            for c in range(cols):
                if grid2[r][c] == 1 and (r, c) not in visited:
                    visited.add((r, c))
                    is_sub = grid1[r][c] == 1
                    bfs = deque([(r, c)])
                    while bfs:
                        cur_r, cur_c = bfs.popleft()
                        for nr, nc in nbr:
                            nr, nc = nr + cur_r, nc + cur_c
                            if 0 <= nr < rows and 0 <= nc < cols and grid2[nr][nc] == 1 and (nr, nc) not in visited:
                                visited.add((nr, nc))
                                bfs.append((nr, nc))
                                if grid1[nr][nc] == 0 and is_sub:
                                    is_sub = False
                    if is_sub:
                        res += 1
        return res