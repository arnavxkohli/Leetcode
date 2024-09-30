from typing import List


class Solution:

    def __init__(self):
        self.cache = {}
        self.prices = None
        self.fee = None

    def dp(self, index, can_buy):
        if index == len(self.prices): return 0
        if (index, can_buy) in self.cache: return self.cache[(index, can_buy)]
        result = 0
        if can_buy:
            result = max(self.dp(index+1, False) - self.prices[index] - self.fee, self.dp(index+1, True))
        else:
            result = max(self.dp(index+1, True) + self.prices[index], self.dp(index+1, False))
        self.cache[(index, can_buy)] = result
        return result

    def maxProfit(self, prices: List[int], fee: int) -> int:
        self.prices, self.fee = prices, fee
        return self.dp(0, True)
