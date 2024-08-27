from typing import List
from collections import defaultdict


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        prefix, running_sum = defaultdict(int), 0
        prefix[0] += 1
        for num in enumerate(nums):
            running_sum += num
            if running_sum - k in prefix:
                res += prefix[running_sum-k]
            prefix[running_sum] += 1
        return res
