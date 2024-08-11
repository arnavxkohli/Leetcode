# Pacific Atlantic Water Flow

This question is a matrix kind of question disguised as a graph question. It was asked to you at google (well an iteration of it was asked).

There are some tricks that are used in the question:
1. Since we are finding all cells that can be reached by both pacific and atlantic we can do a bfs from the cells directly next to the ocean (boundary cells) and reverse the condition (so only move up if the neighbor has higher or equal amount of elevation).
2. Start a bfs on the edges for that particular ocean.
3. Maintain two sets for the pacific and atlantic reachable coordinates. If a coordinate is present in the ocean set, then we can skip it, otherwise implement the condition given in the next point
4. The first thing we need is a bounds check, the second thing we need is to see if the elevation increases or stays the same.
5. Find the intersection of the two sets with `&`.
