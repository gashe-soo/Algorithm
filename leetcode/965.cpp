/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* node, int val)
    {
        if (node == nullptr)
            return true;

        if (node->val != val)
            return false;

        return check(node->left, val) && check(node->right, val);
    }

    bool isUnivalTree(TreeNode* root)
    {
        return check(root, root->val);
    }
};