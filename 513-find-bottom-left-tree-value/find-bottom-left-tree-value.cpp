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
    void f(TreeNode* root,int level,vector<pair<int,int>> &ans){
        if(root==NULL) return;
        ans.push_back({root->val,level});
        f(root->left,level+1,ans);
        f(root->right,level+1,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<pair<int,int>> ans;
        f(root,0,ans);
        int left=root->val;
        int maxi=-1;
        for(auto it:ans){
            if(it.second>maxi){
                left=it.first;
                maxi=it.second;
            }
        }
        return left;

    }
};