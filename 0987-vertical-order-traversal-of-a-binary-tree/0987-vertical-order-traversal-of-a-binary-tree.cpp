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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //Create a map with col and then row as key and vector of nodes as values
        map<int, map<int, vector<int>>> mpp;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            mpp[col][row].push_back(node -> val);
            if(node -> left) q.push({node -> left, {row + 1, col - 1}});
            if(node -> right) q.push({node -> right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;
        for(auto c : mpp) {
            vector<int> colVals;
            for(auto r : c.second) {
                sort(r.second.begin(), r.second.end());
                for(int x : r.second)
                    colVals.push_back(x);
            }
            ans.push_back(colVals);
        }
        return ans;
    }
};