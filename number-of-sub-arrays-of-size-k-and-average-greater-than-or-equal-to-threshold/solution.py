from typing import List


class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        running_sum = sum(arr[:k])
        res = int(running_sum/k >= threshold)
        for i in range(k, len(arr)):
            running_sum += arr[i] - arr[i-k]
            res += int(running_sum/k >= threshold)
        return res
