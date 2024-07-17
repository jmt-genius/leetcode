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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> delset(to_delete.begin(),to_delete.end());
        vector<TreeNode*> forest;
        
        root=processnode(root,delset,forest);
        if(root){
            forest.push_back(root);
        }
        return forest;
        
    }
private:
    TreeNode* processnode(TreeNode* node,unordered_set<int>& del,vector<TreeNode*>& forest){
        if(!node){
            return nullptr;
        }

        node->left=processnode(node->left,del,forest);
        node->right=processnode(node->right,del,forest);

        if(del.find(node->val)!=del.end()){
            if(node->left){
                forest.push_back(node->left);
            }
            if(node->right){
                forest.push_back(node->right);
            }
            delete node;
            return nullptr;
        }
        return node;
    }
};