from typing import Dict


class Solution:
    def largestFactor(self, n: int) -> int:
        res = 1
        for num in range(2, n):
            if n%num == 0:
                res = max(res, num)
        return res

    def dp(self, n, memo=None):
        if memo is None:
            memo = {1:0}
        if n not in memo:
            largest_factor = self.largestFactor(n)
            memo[n] = int(n/largest_factor) + self.dp(largest_factor)
        return memo[n]

    def minSteps(self, n: int) -> int:
        return self.dp(n)
