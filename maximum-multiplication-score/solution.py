from typing import List


class Solution:
    def __init__(self):
        self.memo = {}
        self.a = None
        self.b = None

    def dp(self, a_ptr, b_ptr):
        if a_ptr == len(self.a):
            return 0
        if b_ptr == len(self.b):
            return -10**9
        if(a_ptr, b_ptr) in self.memo:
            return self.memo[(a_ptr, b_ptr)]
        self.memo[(a_ptr, b_ptr)] = \
            max(self.a[a_ptr] * self.b[b_ptr] + self.dp(a_ptr+1, b_ptr+1),
                self.dp(a_ptr, b_ptr+1))
        return self.memo[(a_ptr, b_ptr)]

    def maxScore(self, a: List[int], b: List[int]) -> int:
        self.a, self.b = a, b
        return self.dp(0, 0)
