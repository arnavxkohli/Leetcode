from typing import List


class BestSolution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for r in range(n):
            for c in range(r, n):
                matrix[r][c], matrix[c][r] = matrix[c][r], matrix[r][c]
        for row in matrix:
            row.reverse()


class InvolvedSolution:
    def rotate(self, matrix: List[List[int]]) -> None:
        displaced, n = {}, len(matrix)
        for r in range(n):
            swap = [matrix[r][c] if (r, c) not in displaced else displaced[(r, c)] for c in range(n)]
            for c in range(n):
                if (c, n-1-r) not in displaced:
                    displaced[(c, n-1-r)] = matrix[c][n-1-r]
                matrix[c][n-1-r] = swap[c]
