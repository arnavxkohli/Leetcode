# Path With Maximum Probability

This is a slightly unintuitive Dijkstra's at first. Since it is undirected, the edges are two-way. You might think it can lead to a cycle, but you are reversing the Dijkstra's condition here. You want to find the path with the **maximum** weight, not the minimum. This prevents a cycle.

Another Dijkstra optimization is that you can early return if you encounter the end node. Remember that you only pop off a node from the priority queue (in this case it is a maximum heap), in case it has been "exhausted" which means you know for sure what the lowest distance to that path is.

An alternative method for this problem is the Bellman-Ford algorithm, which works well for graphs with negative weights but can also be adapted for maximizing probabilities. It involves iteratively relaxing all edges and checking if a path through an edge offers a higher probability than the previously known path. This approach can be less intuitive and generally less efficient compared to Dijkstra’s algorithm for this specific problem.
