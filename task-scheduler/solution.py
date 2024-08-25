from collections import Counter, deque
import heapq
from typing import List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq_map = Counter(tasks)
        max_heap, cooldown_queue = [-frequency for frequency in freq_map.values()], deque([])
        heapq.heapify(max_heap)
        cycles = 0
        while max_heap or cooldown_queue:
            cycles += 1
            if max_heap:
                frequency = heapq.heappop(max_heap) + 1
                if frequency:
                    cooldown_queue.append((cycles + n, frequency))
            if cooldown_queue and cooldown_queue[0][0] == cycles:
                heapq.heappush(max_heap, cooldown_queue.popleft()[1])
        return cycles
