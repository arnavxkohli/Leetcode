from typing import List


class Solution:

    def __init__(self):
        self.m = None
        self.prefix = None
        self.cache = {}

    def dp(self, start, end):
        if end - start <= 2: return True
        if (start, end) in self.cache:
            return self.cache[(start, end)]
        result = self.dp(start, start+1) and self.prefix[end] - self.prefix[start+1] >= self.m and self.dp(start+1, end)
        for split in range(start+2, end):
            if self.prefix[split] - self.prefix[start] >= self.m:
                result = result or (self.dp(start, split) and self.dp(split, end))
        self.cache[(start, end)] = result
        return result

    def canSplitArray(self, nums: List[int], m: int) -> bool:
        self.m = m
        prefix = [0]
        for num in nums:
            prefix.append(prefix[-1] + num)
        self.prefix = prefix
        res = self.dp(0, len(nums))
        return res
