from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1 # we need to ensure that the r bound does not exceed the length of nums
        while l < r:
            mid = l + (r-l)//2
            if nums[mid+1] > nums[mid]:
                l = mid + 1
            else:
                r = mid
        return l