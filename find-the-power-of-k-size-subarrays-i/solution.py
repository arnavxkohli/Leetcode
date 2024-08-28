from typing import List


class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        if k == 1: return nums
        prefix = [0]
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]+1:
                prefix.append(prefix[-1]+1)
            else:
                prefix.append(0)
        res = []
        for i in range(k-1, len(prefix)):
            if prefix[i] >= k-1:
                res.append(nums[i])
            else:
                res.append(-1)
        return res
