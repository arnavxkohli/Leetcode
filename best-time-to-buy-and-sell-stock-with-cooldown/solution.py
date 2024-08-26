from typing import List


class Solution:
    def __init__(self):
        self.cache = {}
        self.prices = []

    def dp(self, index, can_buy):
        if index >= len(self.prices):
            return 0
        if (index, can_buy) in self.cache:
            return self.cache[index, can_buy]
        if can_buy:
            self.cache[(index, True)] = max(self.dp(index+1, False) - self.prices[index], self.dp(index+1, True))
            # The maximum of buying now or cooling down
        else:
            self.cache[(index, False)] = max(self.dp(index+2, True) + self.prices[index], self.dp(index+1, False))
            # The maximum of selling and waiting for a cooldown day, or not selling today and leaving the decision for tomorrow
        return self.cache[(index, can_buy)]

    def maxProfit(self, prices: List[int]) -> int:
        self.prices = prices
        return self.dp(0, True)


class WorseSolution:
    def __init__(self):
        self.memo = {}
        self.prices = []

    def dp(self, bought, index):
        if index >= len(self.prices): return 0
        if (bought, index) in self.memo:
            return self.memo[(bought, index)]
        if bought is not None:
            self.memo[(bought, index)] = max(self.prices[index] - bought + self.dp(None, index+2), self.dp(bought, index+1))
        else:
            self.memo[(bought, index)] = max(self.dp(self.prices[index], index+1), self.dp(None, index+1))
        return self.memo[(bought, index)]

    def maxProfit(self, prices: List[int]) -> int:
        self.prices = prices
        return self.dp(None, 0)
