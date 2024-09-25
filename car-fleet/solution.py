from typing import List


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        stack = []
        for t in map(lambda ps: (target - ps[0])/ps[1], sorted([(p, s) for p, s in zip(position, speed)], reverse=True)):
            if len(stack) == 0 or stack[-1] < t: stack.append(t)
        return len(stack)
