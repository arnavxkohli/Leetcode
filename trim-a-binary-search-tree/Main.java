class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) { this.val = val; }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode trimBST(TreeNode root, int low, int high) {
        if(root == null) {
            return null;
        }

        TreeNode trimmedLeft = trimBST(root.left, low, high), trimmedRight = trimBST(root.right, low, high);

        if(root.val < low) {
            return trimmedRight;
        } else if (root.val > high) {
            return trimmedLeft;
        }

        root.left = trimmedLeft;
        root.right = trimmedRight;
        return root;
    }
}


public class Main {
    public static void main(String[] args) {
        System.out.println("Hi");
    }
}