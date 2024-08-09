class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        def find_lca(tree):
            if not tree: return None
            if p.val > tree.val and q.val > tree.val: return find_lca(tree.right)
            elif p.val < tree.val and q.val < tree.val: return find_lca(tree.left)
            else: return tree
        return find_lca(root)