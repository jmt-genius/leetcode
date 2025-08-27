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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool b=true;
        while(!q.empty()){
            int s=q.size();
            vector<int> row;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                row.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            if(!b) reverse(row.begin(),row.end());
            ans.push_back(row);
            b=!b;
        }
        return ans;
    }
};