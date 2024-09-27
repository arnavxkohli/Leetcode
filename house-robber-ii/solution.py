from typing import List


class Solution:
    def __init__(self):
        self.nums = []
        self.memo = {}

    def dp(self, first_robbed, index):
        if index >= len(self.nums):
            return 0
        if (first_robbed, index) in self.memo:
            return self.memo[(first_robbed, index)]
        if index == 0:
            self.memo[(True, 0)] = self.dp(True, index+2) + self.nums[0]
            self.memo[(False, 0)] = self.dp(False, index+1)
            return max(self.memo[True, 0], self.memo[False, 0])
        elif index == len(self.nums)-1:
            self.memo[(first_robbed, index)] = 0 if first_robbed else self.nums[index]
        else:
            self.memo[(first_robbed, index)] = max(self.dp(first_robbed, index+2) + self.nums[index], self.dp(first_robbed, index+1))
        return self.memo[(first_robbed, index)]

    def rob(self, nums: List[int]) -> int:
        self.nums = nums
        return self.dp(None, 0)