from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        candidate = max(nums)
        res = 1
        l = 0
        while l < len(nums):
            r = l
            while r < len(nums) and nums[r] == candidate:
                r += 1
            res = max(res, r-l)
            l = max(r, l+1)
        return res
