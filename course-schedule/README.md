# Course Schedule

This is THE topological sort question. Very important because it is a niche concept within graph theory.

The basic idea is you want to keep track of all incoming edges, that is all the nodes which have 0 of them (which means no other node points to them).

You can put these nodes onto a queue (call them parents) in a bfs sort of algorithm, where you visit all of its children. While visiting the children you can also decrement the number of nodes that point to the children, because in the end you will be adding the parent to the result array. The moment the children have 0 "dependencies" or parents, they become parents themselves and can be added to the end of the queue.

This also works for cycle detection if you know the number of elements you are meant to have in the end. If all elements have not been covered by the time the queue is empty, there was a cycle which caused a circular dependency.
