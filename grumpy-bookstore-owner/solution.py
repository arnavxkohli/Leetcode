from typing import List


class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        if minutes >= len(grumpy): return sum(customers)
        prefix = [0]
        for g, c in zip(grumpy, customers):
            prefix.append(prefix[-1] + (c*(g^1)))
        running_sum = sum(customers[:minutes])
        res = 0
        for i in range(minutes, len(prefix)):
            if i > minutes:
                running_sum += customers[i-1] - customers[i-1-minutes]
            res = max(res, running_sum + prefix[-1] + prefix[i-minutes] - prefix[i])
        return res
