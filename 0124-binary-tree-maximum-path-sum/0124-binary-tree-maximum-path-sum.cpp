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
    int solve(TreeNode* root, int &maxSum){
        if(root == NULL)
            return 0;
        
        int leftPathSum = max(0, solve(root->left, maxSum));
        int rightPathSum = max(0, solve(root->right, maxSum));
        
        int newSum = leftPathSum + rightPathSum + root->val;
        maxSum = max(maxSum, newSum);
        return max(leftPathSum, rightPathSum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        solve(root, maxSum);
        return maxSum;
    }
};