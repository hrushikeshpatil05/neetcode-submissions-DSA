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
    unordered_map<int,int>mp;
    int idx = 0;

    TreeNode* dfs( vector<int>& preorder, vector<int>& inorder,int left, int right) {
        if(left > right) {
            return nullptr;
        }

        int preVal = preorder[idx++];
        TreeNode* node = new TreeNode(preVal);

        int mid = mp[preVal];

        node->left = dfs(preorder,inorder,left,mid-1);
        node->right = dfs(preorder,inorder,mid+1,right);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]] = i;
        }

        return dfs(preorder,inorder,0,inorder.size()-1);
    }
};
