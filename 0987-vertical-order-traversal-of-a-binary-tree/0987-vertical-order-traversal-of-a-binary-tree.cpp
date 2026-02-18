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

//TIME COMPLEXITY O(nlogn) Each node visited and then each node inserted into the map
//SPACE COMPLEXIXTY O(n) n for map, queue and output vector each
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        /*
        SOLUTION LOGIC
        //We break the tree into horizontal and vertical coordinates
        //We make a map with key as col and the values have another map with the key as rows
        //When the map is created and the entire tree is traversed we put them into a 2D array
        */

        map<int, map<int, vector<int>>> mpp;

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int row = it.second.first;
            int col = it.second.second;;

            mpp[col][row].push_back(node->val);

            if(node->left != nullptr)
                q.push({node->left, {row + 1, col - 1}});

            if(node->right != nullptr)
                q.push({node->right, {row + 1, col + 1}});
        }
        //map ready

        vector<vector<int>> ans;

        for(auto c : mpp) {
            vector<int> colVals;
            for(auto r : c.second) {
                sort(r.second.begin(), r.second.end());
                for(int val : r.second) {
                    colVals.push_back(val);
                }
            }
            ans.push_back(colVals);
        }

        return ans;
    }
};