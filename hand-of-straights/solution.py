from typing import List
from collections import Counter, defaultdict


class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize: return False
        hand.sort()
        hand_count = Counter(hand)
        for curr in hand:
            if hand_count[curr] > 0:
                check = curr
                hand_count[curr] -= 1
                for _ in range(1, groupSize):
                    check += 1
                    if check not in hand_count or hand_count[check] == 0: return False
                    hand_count[check] -= 1
        return True
