from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1: return nums[0]
        dp = [nums[0], max(nums[0], nums[1])] + [0] * (len(nums)-2)
        for index in range(2, len(nums)):
            dp[index] = max(nums[index] + dp[index-2], dp[index-1])
        return dp[len(nums)-1]