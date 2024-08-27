from typing import List


class Solution:
    def __init__(self):
        self.prices = []
        self.memo = {}

    def dp(self, index, can_buy, transactions_left):
        if transactions_left == 0 or index >= len(self.prices):
            return 0
        if (index, can_buy, transactions_left) in self.memo:
            return self.memo[(index, can_buy, transactions_left)]
        if can_buy:
            self.memo[(index, can_buy, transactions_left)] = \
                max(self.dp(index+1, True, transactions_left), \
                    self.dp(index+1, False, transactions_left) - self.prices[index])
        else:
            self.memo[(index, can_buy, transactions_left)] = \
                max(self.dp(index+1, False, transactions_left), \
                    self.dp(index+1, True, transactions_left-1) + self.prices[index])
        return self.memo[(index, can_buy, transactions_left)]

    def maxProfit(self, prices: List[int]) -> int:
        self.prices = prices
        return self.dp(0, True, 2)