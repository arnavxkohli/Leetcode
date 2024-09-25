import heapq
from typing import List


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        min_capital_heap = [(c, p) for p, c in zip(profits, capital)]
        heapq.heapify(min_capital_heap)
        max_profit_heap = []
        for _ in range(k):
            while min_capital_heap and min_capital_heap[0][0] <= w:
                _, p = heapq.heappop(min_capital_heap)
                heapq.heappush(max_profit_heap, -p)
            if max_profit_heap:
                w -= heapq.heappop(max_profit_heap)
            else:
                break
        return w
