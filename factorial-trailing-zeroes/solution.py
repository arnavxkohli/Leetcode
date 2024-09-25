from math import floor, log


class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n < 5: return 0
        power_5 = 5 ** floor(log(n, 5))
        res = 0
        while power_5 > 1:
            res += n//power_5
            power_5 //= 5
        return res