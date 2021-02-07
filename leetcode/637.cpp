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
    void doSum(vector<double>& sum, vector<int>& count, TreeNode* node, int h)
    {
        if (node == nullptr)
            return;
        if (h < sum.size()) {
            sum[h] += node->val;
            count[h] += 1;
        } else {
            sum.push_back(node->val);
            count.push_back(1);
        }

        doSum(sum, count, node->left, h + 1);
        doSum(sum, count, node->right, h + 1);

        return;
    }

    vector<double> averageOfLevels(TreeNode* root)
    {

        vector<double> sum;
        vector<int> count;

        doSum(sum, count, root, 0);

        vector<double> ans;

        for (int i = 0; i < sum.size(); i++) {
            ans.push_back(sum[i] / count[i]);
        }

        return ans;
    }
};