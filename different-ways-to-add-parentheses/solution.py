from typing import List


class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        if len(expression) <= 2: return [int(expression)]
        res = []
        for index in range(len(expression)):
            curr = expression[index]
            if curr in '+*-':
                left, right = self.diffWaysToCompute(expression[:index]), self.diffWaysToCompute(expression[index+1:])
                for lnum in left:
                    for rnum in right:
                        if curr == '+':
                            res.append(lnum + rnum)
                        if curr == '*':
                            res.append(lnum * rnum)
                        if curr == '-':
                            res.append(lnum - rnum)
        return res
