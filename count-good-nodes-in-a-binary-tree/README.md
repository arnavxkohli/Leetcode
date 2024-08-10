# Count Good Nodes in Binary Tree

Pretty simple question in the end. Perform a BFS on the binary tree while keeping the maximum value encountered on the path so far with the current state. If the current value is greater or equal to the max value then we can increment the count. We also need to update the max value on the path.
