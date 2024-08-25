from typing import List


class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        if sum(nums1) + nums1.count(0) == sum(nums2) + nums2.count(0): return sum(nums1) + nums1.count(0)
        greater, lesser = (nums1, nums2) if sum(nums1) + nums1.count(0) > sum(nums2) + nums2.count(0) else (nums2, nums1)
        diff = sum(greater) + greater.count(0) - sum(lesser)
        return -1 if lesser.count(0) > diff or lesser.count(0) == 0 else sum(greater) + greater.count(0)


solution = Solution()
solution.minSum([3,2,0,1,0], [6,5,0])
