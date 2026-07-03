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
    pair<bool, int> checkBalance(TreeNode* root) {
        if(root == nullptr) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> leftPath = checkBalance(root -> left);
        pair<bool, int> rightPath = checkBalance(root -> right);

        int diff = abs(leftPath.second - rightPath.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(leftPath.second, rightPath.second) + 1;

        if(leftPath.first && rightPath.first && diff)
            ans.first = true;
        else
            ans.first = false;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return checkBalance(root).first;
    }
};