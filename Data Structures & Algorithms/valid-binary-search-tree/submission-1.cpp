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
    bool dfs(TreeNode* root, int maxValue,int minValue) {
        if(!root) {
            return true;
        }

        if(root->val >= maxValue || root->val <= minValue) {
            return false;
        }

        bool lh = dfs(root->left,root->val,minValue);
        bool rh = dfs(root->right,maxValue,root->val);

        return lh & rh;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MAX,INT_MIN);
    }
};
