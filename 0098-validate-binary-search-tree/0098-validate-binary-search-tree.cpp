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
    bool isValid(TreeNode* root, long long maxVal, long long minVal) {
        if(root == nullptr) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;
        bool leftValid = isValid(root->left, root->val, minVal);
        bool rightValid = isValid(root->right, maxVal, root->val);

        return leftValid && rightValid;
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MAX, LLONG_MIN);
    }
};