from typing import List


class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        curr_nums = nums
        while(len(curr_nums) > 1):
            new_nums = []
            for i in range(1, len(curr_nums)):
                new_nums.append((curr_nums[i] + curr_nums[i-1]) % 10)
            curr_nums = new_nums
        return curr_nums[0]
