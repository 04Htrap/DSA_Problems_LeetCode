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
    TreeNode* buildBST(vector<int>& preorder, int& idx, int upper_bound) {
        if(idx == preorder.size() || preorder[idx] > upper_bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = buildBST(preorder, idx, root->val);
        root->right = buildBST(preorder, idx, upper_bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildBST(preorder, i, INT_MAX);
    }
};