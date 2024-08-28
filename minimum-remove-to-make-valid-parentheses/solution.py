class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        par_open = []
        par_closed = []
        for i, char in enumerate(s):
            if char == '(':
                par_open.append(i)
            if char == ')':
                if not par_open:
                    par_closed.append(i)
                else:
                    par_open.pop()
        invalid = set(par_open + par_closed)
        res = ''
        for i, char in enumerate(s):
            if i not in invalid:
                res += char
        return res