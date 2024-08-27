from typing import List


class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        res = 0
        prefix, running_sum = {0:0}, 0
        for i, num in enumerate(nums):
            running_sum += num
            if running_sum - k in prefix:
                res = max(res, i+1-prefix[running_sum-k])
            if running_sum not in prefix:
                prefix[running_sum] = i+1
        return res
