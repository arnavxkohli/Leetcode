from typing import List


class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = []
        candidate = 1
        for _ in range(n):
            res.append(candidate)
            if candidate * 10 <= n:
                candidate *= 10
            else:
                if candidate == n:
                    candidate //= 10
                candidate += 1
                while candidate % 10 == 0:
                    candidate //= 10
        return res