from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        answers = []
        def backtrack(row, cols, diags, adiags):
            if row == n:
                answers.append(cols[:])
                return
            for col in range(n):
                diag, adiag = row - col, row + col
                if col not in cols and diag not in diags and adiag not in adiags:
                    cols.append(col), diags.append(diag), adiags.append(adiag)
                    backtrack(row+1, cols, diags, adiags)
                    cols.pop(), diags.pop(), adiags.pop()
        backtrack(0, [], [], [])
        res = []
        for answer in answers:
            _answer = []
            for row in answer:
                _ans = ''
                for i in range(n):
                    if i == row:
                        _ans += 'Q'
                    else:
                        _ans += '.'
                _answer.append(_ans)
            res.append(_answer)
        return res
