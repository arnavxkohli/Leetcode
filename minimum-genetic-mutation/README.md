# Minimum Genetic Mutation

This question can be tricky to first solve, but the solution is rather straightforward once it is thought of. It is a simple conditional bfs, across all 32 genes. The reason it is conditional is because you only follow a path which is present in the "gene bank". For every iteration of the bfs, you have to go through 24 other combinations where you have 3 choices per genome. If the modified genome has not been visited before and also belongs to the gene bank, you can explore that path and increment the level by 1. In case it has been visited or it does not belong to the bank and you have exhausted all options, simple return -1.

A recursive solution has also been added, which implements a bfs without a queue data structure. Would be good to study in case this is asked.
