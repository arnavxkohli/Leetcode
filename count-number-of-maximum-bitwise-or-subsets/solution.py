from typing import List


class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or = 0
        for num in nums: max_or |= num
        def backtrack(index, curr_or):
            if index == len(nums):
                return 1 if curr_or == max_or else 0
            return backtrack(index+1, curr_or | nums[index]) + backtrack(index+1, curr_or)
        return backtrack(0, 0)
