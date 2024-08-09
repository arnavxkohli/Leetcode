from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def backtrack(curr, used_open, used_closed):
            if len(curr) == n * 2:
                res.append(curr)
                return
            if used_open < n:
                backtrack(curr + '(', used_open + 1, used_closed)
            if used_closed < used_open:
                backtrack(curr + ')', used_open, used_closed + 1)
        backtrack('', 0, 0)
        return res