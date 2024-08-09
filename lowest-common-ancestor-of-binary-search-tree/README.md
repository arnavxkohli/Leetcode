# Lowest Common Ancestor of a Binary Search Tree

This is the easier brother of the question lowest common ancestor of a binary tree. Since a Binary Search Tree (in the traditional sense and on leetcode mostly) is stricly increasing, you mainly have three cases:
1. If both `p` and `q`'s values are greater than the current node's value, then the lca is in the right subtree of the current tree
2. If both `p` and `q`'s values are less than the current node's value, then the lca is in the left subtree of the current tree
3. If either `p` or `q` has the same value as the current tree, then we have found our lca. This is also possible if the current node's value lies between `p`'s and `q`'s.
There is a fourth case in which the tree is `None` and there is no lca, but the constraints ensure this is never the case.
Implementing a dfs with the above in mind (either via stack or recursion) will yield the correct answer.
