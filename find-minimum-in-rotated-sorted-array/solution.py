from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        res = 10 ** 9
        while l <= r:
            mid = l + (r-l)//2
            res = min(res, nums[mid])
            if nums[mid] < nums[r]:
                r = mid-1
            else:
                l = mid+1
        return res