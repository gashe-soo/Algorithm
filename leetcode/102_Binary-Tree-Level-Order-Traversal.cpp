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
    void solve(vector<vector<int>>& ans, int d, TreeNode* node)
    {
        if (node == nullptr)
            return;
        if (ans.size() <= d) {
            vector<int> n;
            ans.push_back(n);
        }
        ans[d].push_back(node->val);
        solve(ans, d + 1, node->left);
        solve(ans, d + 1, node->right);
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        solve(ans, 0, root);
        return ans;
    }
};