from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        l_max, r_max = -float('inf'), -float('inf')
        l, r = 0, len(height)-1
        res = 0
        while l < r:
            l_max, r_max = max(l_max, height[l]), max(r_max, height[r])
            res += (l_max - height[l]) + (r_max - height[r])
            if l_max < r_max:
                l += 1
            else:
                r -= 1
        return res