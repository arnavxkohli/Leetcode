from typing import List
from collections import deque


class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        if k > len(arr): return max(arr)
        arr = deque(arr)
        wins, winner = 0, -1
        while wins < k:
            first, second = arr.popleft(), arr.popleft()
            curr_winner, curr_loser = max(first, second), min(first, second)
            if curr_winner == winner:
                wins += 1
            else:
                wins, winner = 1, curr_winner
            arr.appendleft(curr_winner), arr.append(curr_loser)
        return winner