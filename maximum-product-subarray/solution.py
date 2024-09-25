from typing import List


class Solution:
    def __init__(self):
        self.cache = {}
        self.nums = None

    def dp(self, left, right, product):
        if right == len(self.nums):
            return product
        if (left, right) in self.cache:
            return self.cache[(left, right)]

        include_current = self.dp(left, right + 1, product * self.nums[right])
        start_new_product = self.dp(right, right + 1, self.nums[right])

        result = max(include_current, start_new_product)
        self.cache[(left, right)] = result
        return result

    def maxProduct(self, nums: List[int]) -> int:
        self.nums = nums
        return self.dp(0, 0, 1)