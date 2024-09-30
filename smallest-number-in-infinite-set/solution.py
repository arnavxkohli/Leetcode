import heapq


class SmallestInfiniteSet:

    def __init__(self):
        self.min_heap = []
        self.increment = 1
        self.heap_contents = set()

    def popSmallest(self) -> int:
        if self.min_heap and self.min_heap[0] < self.increment:
            res = heapq.heappop(self.min_heap)
            self.heap_contents.remove(res)
            return res
        else:
            self.increment += 1
            return self.increment - 1

    def addBack(self, num: int) -> None:
        if num >= self.increment:
            return
        if num not in self.heap_contents:
            self.heap_contents.add(num)
            heapq.heappush(self.min_heap, num)
