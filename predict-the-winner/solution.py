from typing import List


class Solution:

    def __init__(self):
        self.nums = None
        self.memo = {}

    def dp(self, l, r):
        if l > r:
            return 0
        if (l, r) not in self.memo:
            self.memo[l, r] = max(self.nums[l] - self.dp(l+1, r), self.nums[r] - self.dp(l, r-1))
        return self.memo[l, r]

    def predictTheWinner(self, nums: List[int]) -> bool:
        self.nums = nums
        return self.dp(0, len(nums)-1) >= 0
