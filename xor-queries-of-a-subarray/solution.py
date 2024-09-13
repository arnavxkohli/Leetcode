from typing import List


class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        prefix, res = [0], []
        for num in arr: prefix.append(prefix[-1] ^ num)
        for l, r in queries: res.append(prefix[l] ^ prefix[r+1])
        return res
