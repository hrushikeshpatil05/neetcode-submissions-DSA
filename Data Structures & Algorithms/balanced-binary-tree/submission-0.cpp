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
    bool isBalancedHeight = true;
    int solve(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int leftHeight = 1 + solve(root->left);
        int rightHeight = 1 + solve(root->right);

        if(abs(leftHeight-rightHeight) > 1) {
            isBalancedHeight = false;
        }

        return max(leftHeight,rightHeight);

    }
    bool isBalanced(TreeNode* root) {
        solve(root);
        return isBalancedHeight;
    }
};
