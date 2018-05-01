package construct_binary_tree_from_preorder_and_inorder_traversal;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder, 0, inorder, 0, inorder.length - 1);
    }

    private TreeNode helper(int[] preorder, int preIndex, int[] inorder, int inLow, int inHigh) {
        if (preIndex == preorder.length || inLow > inHigh) {
            return null;
        }
        int rootVal = preorder[preIndex];
        TreeNode root = new TreeNode(rootVal);
        int inIndex = 0;
        for (int i = inLow; i <= inHigh; i++) {
            if (inorder[i] == rootVal) {
                inIndex = i;
                break;
            }
        }
        root.left = helper(preorder, preIndex + 1, inorder, inLow, inIndex - 1);
        root.right = helper(preorder, preIndex + inIndex - inLow + 1, inorder, inIndex + 1, inHigh);
        return root;
    }
}
