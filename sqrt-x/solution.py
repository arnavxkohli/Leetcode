class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1: return x
        l, r = 1, x
        while l <= r:
            mid = l + (r-l)//2
            if mid ** 2 == x: return mid
            if mid ** 2 < x: l = mid+1
            else: r = mid-1
        return r