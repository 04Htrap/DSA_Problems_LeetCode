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
    TreeNode* findMin(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            //0 Child
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }

            //1Child
            if(root->left != nullptr && root-> right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            if(root->left == nullptr && root-> right != nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            //2 Child
            if(root->left != nullptr && root-> right != nullptr){
                int mini = findMin(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
            
        }
        return root;
    }
};