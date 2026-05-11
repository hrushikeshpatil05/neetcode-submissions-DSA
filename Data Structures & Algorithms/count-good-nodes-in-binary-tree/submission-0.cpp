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
    int ans = 0;
    void solve(TreeNode* root, int maxValue) {
        if(!root) return;

        if(root->val >= maxValue) {
            ans++;
        }

        solve(root->left,max(maxValue,root->val));
        solve(root->right,max(maxValue,root->val));
    }
    int goodNodes(TreeNode* root) {
        solve(root,-100);
        return ans;
    }
};
