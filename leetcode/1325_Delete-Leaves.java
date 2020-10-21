/**
 * Definition for a binary tree node. 
public class TreeNode { 
    int val; 
    TreeNode left; 
    TreeNode right; 
    TreeNode() {} 
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) { 
        this.val = val; 
        this.left= left; 
        this.right = right; 
    } 
}
 */
class Solution {

  public TreeNode removeLeafNodes(TreeNode root, int target) {
    if (remove(root, target)) return null;
    return root;
  }

  public boolean remove(TreeNode node, int target) {
    if (isObject(node, target)) return true;

    if (node.left != null) {
      if (isObject(node.left, target)) {
        node.left = null;
      } else {
        if (remove(node.left, target)) node.left = null;
      }
    }

    if (node.right != null) {
      if (isObject(node.right, target)) {
        node.right = null;
      } else {
        if (remove(node.right, target)) node.right = null;
      }
    }

    return isObject(node, target);
  }

  public boolean isObject(TreeNode node, int target) {
    return isLeaf(node) && node.val == target;
  }

  private boolean isLeaf(TreeNode node) {
    return node.left == null && node.right == null;
  }
}
