class Solution:
    def __init__(self):
        self.s, self.p = '', ''
        self.memo = {}

    def dp(self, s_index, p_index):
        if p_index == len(self.p):
            return len(self.s) == s_index
        if s_index == len(self.s):
            return all(char == '*' for char in self.p[p_index:])
        if (s_index, p_index) in self.memo:
            return self.memo[(s_index, p_index)]
        if self.p[p_index] == '*':
            self.memo[(s_index, p_index)] = self.dp(s_index, p_index+1) or self.dp(s_index+1, p_index) or self.dp(s_index+1, p_index+1)
        elif self.p[p_index] == '?' or self.p[p_index] == self.s[s_index]:
            self.memo[(s_index, p_index)] = self.dp(s_index+1, p_index+1)
        else:
            self.memo[(s_index, p_index)] = False
        return self.memo[(s_index, p_index)]

    def isMatch(self, s: str, p: str) -> bool:
        self.s, self.p = s, p
        return self.dp(0, 0)