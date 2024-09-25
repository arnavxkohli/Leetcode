from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        half = (len(nums1) + len(nums2))//2 - 1
        l, r = 0, len(nums1)-1
        mid = l + (r-l)//2
        print(mid, half-mid)
        return 0.0