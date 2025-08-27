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
    int f(TreeNode* root,int d){
        
        if(root->left==NULL && root->right==NULL) return d;
        int left=INT_MIN,right=INT_MIN;
        if(root->left) left=f(root->left,d+1);
        if(root->right) right=f(root->right,d+1);
        return max(left,right);

    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return f(root,1);
        
    }
};