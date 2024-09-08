from typing import List


class Solution:
    def __init__(self):
        self.memo = {}
        self.nums = []

    def dp(self, i, t):
        if(i, t) in self.memo:
            return self.memo[(i, t)]
        if i == len(self.nums):
            return int(t == 0)
        self.memo[(i, t)] = self.dp(i+1, t-self.nums[i]) + self.dp(i+1, t+self.nums[i])
        return self.memo[(i, t)]

    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        self.nums = nums
        return self.dp(0, target)
