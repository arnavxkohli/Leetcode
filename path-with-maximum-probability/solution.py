from typing import List
import heapq


class BellmanFordSolution:

    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        distances = [1 if i == start_node else 0 for i in range(n)]
        for _ in range(n):
            update = False
            for (e1, e2), w in zip(edges, succProb):
                if distances[e1] * w > distances[e2]:
                    distances[e2] = distances[e1] * w
                    update = True
                if distances[e2] * w > distances[e1]:
                    distances[e1] = distances[e2] * w
                    update = True
            if not update:
                break
        return distances[end_node]


class DijkstraSolution:

    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        graph = [[] for _ in range(n)]
        for (start, end), weight in zip(edges, succProb):
            graph[start].append((end, weight))
            graph[end].append((start, weight))
        distances, max_heap = [1 if i == start_node else 0 for i in range(n)], [(-1, start_node)]
        heapq.heapify(max_heap)
        while max_heap:
            distance, cur = heapq.heappop(max_heap)
            distance = -distance
            if cur == end_node:
                return distance
            for nex, weight in graph[cur]:
                if distance * weight > distances[nex]:
                    distances[nex] = distance * weight
                    heapq.heappush(max_heap, (-distances[nex], nex))
        return 0.0
