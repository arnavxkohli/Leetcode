import java.util.ArrayDeque;
import java.util.ArrayList;

class TreeNode {
    int val;
    TreeNode right;
    TreeNode left;

    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        if(root == null || (root.left == null && root.right == null)) {
            return root;
        }

        ArrayDeque<TreeNode> bfsQueue = new ArrayDeque<>();

        bfsQueue.add(root);
        int level = 0;

        while(!bfsQueue.isEmpty()) {
            int levelSize = bfsQueue.size();
            ArrayList<TreeNode> levelNodes = new ArrayList<>();

            for(int i = 0; i < levelSize; i++) {
                TreeNode node = bfsQueue.pollFirst();
                if(node.left != null) {
                    bfsQueue.add(node.left);
                }
                if(node.right != null) {
                    bfsQueue.add(node.right);
                }
                levelNodes.add(node);
            }

            if((level % 2) == 1) {
                int start = 0, end = levelNodes.size() - 1;
                while(start < end) {
                    int temp = levelNodes.get(start).val;
                    levelNodes.get(start).val = levelNodes.get(end).val;
                    levelNodes.get(end).val = temp;
                    start++; end--;
                }
            }

            level++;
        }

        return root;
    }
}

public class Main {
    public static void main(String[] args) {  }
}