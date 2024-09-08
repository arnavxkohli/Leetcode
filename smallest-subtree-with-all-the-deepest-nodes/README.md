# Smallest Subtree With all the Deepest Nodes

This is a good question. Basically the trick is that if the left subtree has a higher depth then it will obviously be the tree with all the deepest nodes. Same for the right subtree. If they have the same depth, then going to the left or the right subtree would discount the other subtree's deepest nodes. Similar to LCA tbh.

This question is the same as Leetcode 1123 btw.
