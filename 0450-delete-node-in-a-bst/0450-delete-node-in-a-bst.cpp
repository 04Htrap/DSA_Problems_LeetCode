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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        //Now the node is found so we start deleting in 3 ways: 0, 1, 2 Children
        else{
            //Case with 0 child
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            //Case with 1 child on left
            if(root->left != nullptr && root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //Case with 1 child on right
            if(root->left == nullptr && root->right != nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            //Final case with 2 children
            if(root->left != nullptr && root-> right != nullptr){
                int mini = findMin(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }
        return root;
    }
    TreeNode* findMin(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
};