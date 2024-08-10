from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val, self.left, self.right = val, left, right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        bfs = deque([(root, root.val)])
        count = 1
        while bfs:
            length = len(bfs)
            for _ in range(length):
                node, max_val = bfs.popleft()
                if node.left:
                    if node.left.val >= max_val:
                        count += 1
                        bfs.append((node.left, node.left.val))
                    else:
                        bfs.append((node.left, max_val))
                if node.right:
                    if node.right.val >= max_val:
                        count += 1
                        bfs.append((node.right, node.right.val))
                    else:
                        bfs.append((node.right, max_val))
        return count