/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != nullptr) {
            //p in left or q in right or vice versa
            if((p->val <= root->val && q->val >= root->val) || (p->val >= root->val && q->val <= root->val))
                return root;
            
            //both p and q in left
            if (p->val < root->val && q->val < root->val)
                    root = root->left;
            //both p and q in right
            else root = root->right;
        }
        return nullptr;
    }
};