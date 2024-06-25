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
 #include<vector>
class Solution {
public:
    vector<int> r;
    void traverse(TreeNode* ro){
        if(ro){
            traverse(ro->left);
            r.push_back(ro->val);
            
            traverse(ro->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return r;
        
    }

};