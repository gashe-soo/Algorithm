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
    /*
    binary search tree이므로 node.left는 node보다 작은 값, right는 큰 값
    => inorder traverse로 순서를 정할 수 있다.
    순서대로 배열에 넣어서 k번째 수를 꺼내오면 답.   
    
    */

    vector<int> ans;

    int kthSmallest(TreeNode* root, int k)
    {
        inorder(root);
        return ans[k - 1];
    }

    void inorder(TreeNode* node)
    {
        if (node == NULL)
            return;
        if (node->left != NULL)
            inorder(node->left);
        ans.push_back(node->val);
        if (node->right != NULL)
            inorder(node->right);
    }
};