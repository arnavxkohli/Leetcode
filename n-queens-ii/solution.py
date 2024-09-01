class Solution:
    def totalNQueens(self, n: int) -> int:
        self.res = 0
        def backtrack(row, cols, diags, adiags):
            if row == n:
                self.res += 1
                return
            for col in range(n):
                diag, adiag = row - col, row + col
                if col not in cols and diag not in diags and adiag not in adiags:
                    cols.append(col), diags.append(diag), adiags.append(adiag)
                    backtrack(row+1, cols, diags, adiags)
                    cols.pop(), diags.pop(), adiags.pop()
        backtrack(0, [], [], [])
        return self.res
