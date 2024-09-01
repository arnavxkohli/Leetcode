from typing import List


class Solution:
    def __init__(self):
        self.memo = {}
        self.prices = []

    def dp(self, index, can_buy, k):
        if k == 0 or index >= len(self.prices):
            return 0
        if(index, can_buy, k) in self.memo:
            return self.memo[(index, can_buy, k)]
        if can_buy:
            self.memo[(index, can_buy, k)] = max(self.dp(index+1, True, k), \
                self.dp(index+1, False, k) - self.prices[index])
        else:
            self.memo[(index, can_buy, k)] = max(self.dp(index+1, False, k), \
                self.dp(index+1, True, k-1) + self.prices[index])
        return self.memo[(index, can_buy, k)]

    def maxProfit(self, k: int, prices: List[int]) -> int:
        self.prices = prices
        return self.dp(0, True, k)
