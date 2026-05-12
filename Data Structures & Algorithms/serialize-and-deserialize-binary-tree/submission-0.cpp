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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "N,";
        }

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return solve(data);
    }

    int idx = 0;
    TreeNode* solve(string data) {

        if(data[idx] == 'N') {
            idx += 2;
            return nullptr;
        }

        string val = "";
        while(data[idx] != ',') {
            val += data[idx++];
        }

        idx++;

        TreeNode* root = new TreeNode(stoi(val));

        root->left = solve(data);
        root->right = solve(data);

        return root;
    }
};
